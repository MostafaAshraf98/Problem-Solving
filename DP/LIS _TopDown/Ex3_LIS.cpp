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

int solve(vi &v, vi &memo, int currentIndex) {
    if (memo[currentIndex] != -1)
        return memo[currentIndex];
    int lis_current = 1; // the least increasing subsequence of the current element is initially of 1
    for (int i = 0; i < currentIndex; i++) {
        int ithLIS = solve(v, memo, i);
        if (v[i] < v[currentIndex] && ithLIS >= lis_current)
            lis_current = ithLIS + 1;
    }
    memo[currentIndex] = lis_current;

}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n;
    sf(n);
    vi v(n);
    vi memo(n, -1);
    for (int i = 0; i < n; i++)
        sf(v[i]);
    solve(v, memo, 0);
    int LIS = INT_MIN;
    for (int i = 0; i < n; i++)
        LIS = max(LIS, memo[i]);
    cout << LIS << endl;
    return 0;
}