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
//const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2423
//ACCEPTED

int N;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    while (sf(N) && N != 0) {
        bool found = false;
        for (int x = 1; x < sqrt(N); x++) {
            ll cubicx = x * x * x;
            if (cubicx < N)
                continue;
            for (int y = 1; y < x; y++) {
                ll cubicy = y * y * y;
                if (N == cubicx - cubicy) {
                    cout << x << " " << (int) y << endl
                    found = true;
                    break;

                }
            }
            if (found) {
                break;
            }
        }
        if (!found)
            cout << "No solution" << endl;
    }

    return 0;
}

// N = x^3 - y^3
// you have y^3 = x^3 - N
// x^3 = y^3 + N
// x = cubic root of (y^3 +N)