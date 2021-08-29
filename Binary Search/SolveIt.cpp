#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282
//ACCEPTED

//In mathematics, the bisection method is a root-finding method that applies to any continuous functions for which one knows two values with opposite signs.

float p, q, r, s, t, u;

float f(float x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}


double bisection() {
    double lo = 0, hi = 1;
    while (lo + (1e-7) < hi) {
        double x = (lo + hi) / 2;
        if (f(lo) * f(x) <= 0)
            // this mean that f(x) is positive
            hi = x;
        else
            // this means that f(x) is negative
            lo = x;
    }
    return (lo + hi) / 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0)*f(1)>0) // this means that both are negative or both are positive
        {
            cout << "No solution" << endl;
        }
        else
            cout << fixed << setprecision(4) << bisection() << endl;
    }
    return 0;
}