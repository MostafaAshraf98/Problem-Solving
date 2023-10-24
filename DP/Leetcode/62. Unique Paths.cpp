#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)
#define sfs(s) scanf("%s", s)

#define pf(n) printf("%d", n)
#define pff(n, m) printf("%d %d", n, m)
#define pfl(n) printf("%I64d", n)
#define pffl(n, m) printf("%I64d %I64d", n, m)
#define pfs(s) printf("%s", s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int)10e4;

//Accepted
//DP

class Solution
{
public:
    int m;
    int n;
    vector<vector<int>> memo;
    int solve(int row, int col)
    {
        if (row == m || row < 0 || col == n || col < 0)
            return 0;

        if(row==m-1 && col == n-1)
            return 1;

        if (memo[row][col] != -1)
            return memo[row][col];

        int result = solve(row, col + 1);
        result += solve(row + 1, col);

        return memo[row][col] = result;
    }
    int uniquePaths(int m, int n)
    {
        this->m = m;
        this->n = n;
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return solve(0, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}