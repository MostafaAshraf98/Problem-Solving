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

//https://codeforces.com/contest/79/problem/B
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n;// number of rows
    int m; // number of columns
    int k; // number of wastes
    int t; // number of queries
    ll x, y;
    sff(n, m);
    sff(k, t);

    set<ll> s;
    vector<ll> vec; // this is the vecgor of the locations of the wastes if we made it a line instead of a 2D matrix

    while (k--) {
        sffl(x, y);
        x--; // because now we have only
        vec.push_back(x * m + y);
    }
    sort(vec.begin(), vec.end());

    ll pos;
    while (t--) {
        sffl(x, y);
        x--;
        pos = m * x + y;
        ll k = 0; // counts the number of waste until this pos
        int j = 0; //tells you if this pos is waste
        for (auto e : vec) {
            if (e < pos) {
                k++;
            } else if (e == pos) {
                j = 1;
            } else {
                break;
            }
        }
        pos -= k; // removes the cells with the waste until this pos
        pos = pos % 3;
        if (j)
            pfs("Waste");
        else if (pos == 1)
            pfs("Carrots");
        else if (pos == 2)
            pfs("Kiwis");
        else
            pfs("Grapes");
        nl;
    }
    return 0;
}