#include <vector>
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

// if all ones 1111111111 => return 10e9
// if all zeroes 00000000 => return -1
// if ones and zeroes 111000 => return max
class Solution
{
public:
    vector<vector<int>> fireTimes;
    vector<vector<vector<int>>> dp;
    vector<vector<bool>> visited;
    int n;
    int m;
    int start = 0;
    int end = -1;
    vector<vector<int>> spreadFire(vector<vector<int>> state, bool &changed, int currentTime)
    {
        vector<vector<int>> newState(n, vector<int>(m, -1));

        return newState;
    }

    bool solve(int currentRow, int currentCol, int currentTime)
    {
        if (currentRow == n - 1 && currentCol == m - 1)
            return true;
        vector<vector<int>> currentGrid = fireStates[currentTime];
        if (currentGrid[currentRow][currentCol] == 1)
            return false;

        bool up = false;
        if (currentRow - 1 >= 0)
            bool down = false;
        bool right = false;
        bool left = false;
    }

    int BS()
    {
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        this->n = grid.size();
        this->m = grid[0].size();
        bool changed = true;
        fireTimes = vector<vector<int>>(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    fireTimes[i][j] = 0;
        int currentTime = 1;
        while (changed)
        {
            changed = true;
            vector<vector<int>> newState = spreadFire(fireStates[fireStates.size() - 1], changed);
            if (!changed)
                break;
        }
    }
};

// int main()
// {
//     ios_base::sync_with_stdio(0), cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
// #endif
//     return 0;
// }