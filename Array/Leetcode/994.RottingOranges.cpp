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

    int orangesRotting(vector<vector<int>> &grid) {
        int time = 0;
        while (true) {
            bool found = false;
            vector<vector<int>> cop(grid);
            for (int i = 0; i < grid.size(); i++)
                for (int j = 0; j < grid[0].size(); j++) {
                    if (cop[i][j] == 2) {
                        if (i - 1 >= 0) {
                            if (grid[i - 1][j] == 1) {
                                found = true;
                                grid[i - 1][j] = 2;
                            }
                        }
                        if (i + 1 < grid.size()) {
                            if (grid[i + 1][j] == 1) {
                                found = true;
                                grid[i + 1][j] = 2;
                            }
                        }

                        if (j - 1 >= 0) {
                            if (grid[i][j - 1] == 1) {
                                found = true;
                                grid[i][j - 1] = 2;
                            }
                        }
                        if (j + 1 < grid[0].size()) {
                            if (grid[i][j + 1] == 1) {
                                found = true;
                                grid[i][j + 1] = 2;
                            }
                        }
                    }
                }
            if (!found)
                break;
            time++;
        }

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
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