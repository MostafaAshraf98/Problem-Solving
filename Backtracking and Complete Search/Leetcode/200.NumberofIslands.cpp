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

class Solution {

public :
    void solve(vector<vector<char>> &grid, int row, int col) {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0')
            return;

        grid[row][col] = '0';
        solve(grid, row + 1, col);
        solve(grid, row - 1, col);
        solve(grid, row, col + 1);
        solve(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        int answer = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    answer++;
                    solve(grid,i,j);
                }
            }
        return answer;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}