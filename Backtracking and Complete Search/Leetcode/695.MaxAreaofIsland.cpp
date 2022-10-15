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
public:
    int calc(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size())
            return 0;
        if (grid[row][col] == 0)
            return 0;
        int ans = 1;
        grid[row][col] = 0;
        // move left
        ans += calc(grid, row, col - 1);
        // move right
        ans += calc(grid, row, col + 1);

        // move up
        ans += calc(grid, row - 1, col);

        // move down
        ans += calc(grid, row + 1, col);

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int area = calc(grid,i, j);
                if (area > max)
                    max = area;
            }
        }
        return max;
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