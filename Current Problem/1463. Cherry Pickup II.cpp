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

// Accepted
// DP

class Solution
{
public:
    int n;
    int m;
    vector<vector<vector<int>>> memo;
    int solve(const vector<vector<int>> &grid, int row, int col1, int col2)
    {
        if (row >= n || col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return 0;
        if (memo[row][col1][col2] != -1)
            return memo[row][col1][col2];
            
        int bestScore = INT_MIN;
        // left left
        bestScore = max(bestScore, solve(grid, row + 1, col1 - 1, col2 - 1));
        // left middle
        bestScore = max(bestScore, solve(grid, row + 1, col1 - 1, col2));
        // left right
        bestScore = max(bestScore, solve(grid, row + 1, col1 - 1, col2 + 1));
        // middle left
        bestScore = max(bestScore, solve(grid, row + 1, col1, col2 - 1));
        // middle middle
        bestScore = max(bestScore, solve(grid, row + 1, col1, col2));
        // middle right
        bestScore = max(bestScore, solve(grid, row + 1, col1, col2 + 1));
        // right left
        bestScore = max(bestScore, solve(grid, row + 1, col1 + 1, col2 - 1));
        // right middle
        bestScore = max(bestScore, solve(grid, row + 1, col1 + 1, col2));
        // right right
        bestScore = max(bestScore, solve(grid, row + 1, col1 + 1, col2 + 1));

        // If the 2 robots are on the same cell it is only collected once. 
        int currentCellScore = col1 == col2 ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        return memo[row][col1][col2] = currentCellScore + bestScore;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid, 0, 0, m - 1);
    }
};

// Since the robot can only move downward, all the rows above cannot be revised that's why we do not need any visited array memo.
// also it doesn't make any sense for the robots not to move together. because it will not affect the other robot decision knowing 
// the step of the other robot. we will try all the possible combinations and use the state (row, col1, col2) as memoization.

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}