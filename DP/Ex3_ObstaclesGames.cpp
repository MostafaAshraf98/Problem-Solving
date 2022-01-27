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

ll solve(vector<vector<ll>> &grid, ll r, ll c, vector<vector<ll>> &memo, ll row, ll col) {
    if (row >= r || col >= c)
        return 0;
    if (grid[row][col] == -1)
        return 0;

    if (memo[row][col] != -1)
        return memo[row][col];

    if (row == r - 1 && col == c - 1)
        return 1;

    //tansitions
    return memo[row][col] = solve(grid, r, c, memo, row + 1, col) + solve(grid, r, c, memo, row, col + 1);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    ll r, c;
    cin >> r >> c;
    vector<vector<ll>> grid(r, vector<ll>(c, 0));
    for (ll i = 0; i < r; i++)
        for (ll j = 0; j < c; j++)
            cin >> grid[i][j];

    vector<vector<ll>> memo(r, vector<ll>(c, -1));

    cout << solve(grid,r,c,memo,0,0) <<endl;

    return 0;
}