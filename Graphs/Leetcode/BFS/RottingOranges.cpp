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

    void
    RottenNeighbors(vector<vector<int>> &grid, const int currentRow, const int currentCol, queue<pair<int, int>> &q) {
        int n = grid.size();
        int m = grid[0].size();
        // up
        if (currentRow - 1 >= 0 && grid[currentRow - 1][currentCol] == 1) {
            grid[currentRow - 1][currentCol] = 2;
            q.push(make_pair(currentRow - 1, currentCol));
        }

        //right
        if (currentCol + 1 < m && grid[currentRow][currentCol + 1] == 1) {
            grid[currentRow][currentCol + 1] = 2;
            q.push(make_pair(currentRow, currentCol + 1));
        }

        //down
        if (currentRow + 1 < n && grid[currentRow + 1][currentCol] == 1) {
            grid[currentRow + 1][currentCol] = 2;
            q.push(make_pair(currentRow + 1, currentCol));
        }

        // left
        if (currentCol - 1 >= 0 && grid[currentRow][currentCol - 1] == 1) {
            grid[currentRow][currentCol - 1] = 2;
            q.push(make_pair(currentRow, currentCol - 1));
        }
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int countFresh = 0;
        queue<pair<int, int>>
                q; // this queue hold the positions of rotten tomatoes.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if (grid[i][j] == 1)
                    countFresh++;
            }
        }
        if (countFresh == 0) // there are no fresh tomatoes
            return 0;

        if (q.empty()) // there are no rotten tomatoes
            return -1;

        int time = -1;

        while (!q.empty()) {
            time++;
            int currentRottenCount = q.size();
            for (int i = 0; i < currentRottenCount; i++) {
                pair<int, int> currentRotten = q.front();
                int currentRow = currentRotten.first;
                int currentCol = currentRotten.second;
                q.pop();
                RottenNeighbors(grid, currentRow, currentCol, q);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;

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