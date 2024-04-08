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

// top-down
class Solution
{
public:
    vector<vector<char>> matrix;
    vector<vector<int>> dp;
    int n;
    int m;
    int result = 0;

// the state means that dp[i][j] is the largest side value for the square that has this i and j as its bottom left corner
    int solve(int row, int col)
    {
        if (row == n || col == m)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int right = solve(row, col + 1);
        int up = solve(row + 1, col);
        int upRight = solve(row + 1, col + 1);

        if (matrix[row][col] == '1')
            dp[row][col] = 1 + min(right, min(up, upRight));
        else
            dp[row][col] = 0;

        result = max(result, dp[row][col]);
        return dp[row][col];
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        this->matrix = matrix;
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        solve(0, 0);
        return result *result;
    }
};

// bottom up
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        //The state dp[i][j] means the largest side value for the square that has this i and j as its top right corner
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
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