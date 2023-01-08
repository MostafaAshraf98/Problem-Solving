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

    void getNeighbors(vector<vector<int>> &grid, queue<pair<int, int>> &q, const int &row, const int &col,
                      const int &currentDistance) {
        int n = grid.size();
        int m = grid[0].size();

        //up
        if (row - 1 >= 0 && grid[row - 1][col] == 0) {
            q.push(make_pair(row - 1, col));
            grid[row - 1][col] = currentDistance + 1;
        }

        // up right
        if (row - 1 >= 0 && col + 1 < m && grid[row - 1][col + 1] == 0) {
            q.push(make_pair(row - 1, col + 1));
            grid[row - 1][col + 1] = currentDistance + 1;
        }

        // right
        if (col + 1 < m && grid[row][col + 1] == 0) {
            q.push(make_pair(row, col + 1));
            grid[row][col + 1] = currentDistance + 1;
        }

        // down right
        if (row + 1 < n && col + 1 < m && grid[row + 1][col + 1] == 0) {
            q.push(make_pair(row + 1, col + 1));
            grid[row + 1][col + 1] = currentDistance + 1;
        }

        // down
        if (row + 1 < n && grid[row + 1][col] == 0) {
            q.push(make_pair(row + 1, col));
            grid[row + 1][col] = currentDistance + 1;
        }

        // down left
        if (row + 1 < n && col - 1 >= 0 && grid[row + 1][col - 1] == 0) {
            q.push(make_pair(row + 1, col - 1));
            grid[row + 1][col - 1] = currentDistance + 1;
        }

        //left
        if (col - 1 >= 0 && grid[row][col - 1] == 0) {
            q.push(make_pair(row, col - 1));
            grid[row][col - 1] = currentDistance + 1;
        }

        // up left
        if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == 0) {
            q.push(make_pair(row - 1, col - 1));
            grid[row - 1][col - 1] = currentDistance + 1;
        }

    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {

        if (grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        grid[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> currentNode = q.front();
            q.pop();
            int currentRow = currentNode.first;
            int currentCol = currentNode.second;
            int currentDistance = grid[currentRow][currentCol];
            grid[currentRow][currentCol] = 1;

            if (currentRow == grid.size() - 1 && currentCol == grid[0].size() - 1) {
                return currentDistance;
            }
            getNeighbors(grid, q, currentRow, currentCol, currentDistance);
        }
        return -1;
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
