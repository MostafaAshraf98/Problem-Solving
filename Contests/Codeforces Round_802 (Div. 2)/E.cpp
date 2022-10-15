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

int n, m;

bool checkCell(const vector<vector<int>> &matrix, const int row, const int col) {
    if (row >= n || col >= m || row < 0 || col < 0)
        return true;

    bool found = false;
    if (matrix[row][col] == 1)
        return true;

    // up
    if (row - 1 >= 0 && matrix[row - 1][col] < matrix[row][col])
        found = true;
        //down
    else if (row + 1 < n && matrix[row + 1][col] < matrix[row][col])
        found = true;
        //left
    else if (col - 1 >= 0 && matrix[row][col - 1] < matrix[row][col])
        found = true;
        //right
    else if (col + 1 < m && matrix[row][col + 1] < matrix[row][col])
        found = true;
    if (found)
        return true;
    else
        return false;
}

bool checkCellAndNeighbors(const vector<vector<int>> &matrix, const int i, const int j) {
    bool validSwap = true;
    validSwap &= checkCell(matrix, i, j);
    validSwap &= checkCell(matrix, i + 1, j);
    validSwap &= checkCell(matrix, i - 1, j);
    validSwap &= checkCell(matrix, i, j + 1);
    validSwap &= checkCell(matrix, i, j - 1);
    return validSwap;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    bool solvable = true;
    vector<ii> badCells;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!checkCell(matrix, i, j)) {
                badCells.push_back(make_pair(i, j));
                solvable = false;
            }
        }
    if (solvable) {
        cout << 0 << endl;
        return 0;
    }

    if (badCells.size() > 10) {
        cout << 2 << endl;
        return 0;
    }

    int countSwaps = 0;
    bool solved = false;
    ii s = badCells[0];
    map<ii, bool> neighbours;
    if (s.first - 1 >= 0)
        neighbours[make_pair(s.first - 1, s.second)] = true;
    if (s.first + 1 < n)
        neighbours[make_pair(s.first + 1, s.second)] = true;
    if (s.second - 1 >= 0)
        neighbours[make_pair(s.first, s.second - 1)] = true;
    if (s.second + 1 < m)
        neighbours[make_pair(s.first, s.second + 1)] = true;

    //try to swap the cell itself with any other cell
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (make_pair(i, j) == s)
                continue;
            //swap
            int temp = matrix[s.first][s.second];
            matrix[s.first][s.second] = matrix[i][j];
            matrix[i][j] = temp;
            //check
            bool validSwap = true;
            //Check the cell itself and all its neighbors in both sides
            validSwap &= checkCellAndNeighbors(matrix, s.first, s.second);
            validSwap &= checkCellAndNeighbors(matrix, i, j);
            for (auto badcell: badCells) {
                validSwap &= checkCellAndNeighbors(matrix, badcell.first, badcell.second);
            }

            if (validSwap) {
                countSwaps++;
                solved = true;
            }
            //unswap
            temp = matrix[s.first][s.second];
            matrix[s.first][s.second] = matrix[i][j];
            matrix[i][j] = temp;
        }
    for (auto neighbor: neighbours) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                ii currentIndex = make_pair(i, j);
                ii neighborIndex = neighbor.first;
                if (currentIndex == s || neighbours.find(currentIndex) != neighbours.end())
                    continue;
                //swap
                int temp = matrix[i][j];
                matrix[i][j] = matrix[neighborIndex.first][neighborIndex.second];
                matrix[neighborIndex.first][neighborIndex.second] = temp;
                //check
                bool validSwap = true;
                //Check the cell itself and all its neighbors in both sides
                validSwap &= checkCellAndNeighbors(matrix, neighborIndex.first, neighborIndex.second);
                validSwap &= checkCellAndNeighbors(matrix, i, j);
                for (auto badcell: badCells) {
                    validSwap &= checkCellAndNeighbors(matrix, badcell.first, badcell.second);
                }

                if (validSwap) {
                    countSwaps++;
                    solved = true;
                }
                //unswap
                temp = matrix[i][j];
                matrix[i][j] = matrix[neighborIndex.first][neighborIndex.second];
                matrix[neighborIndex.first][neighborIndex.second] = temp;
            }
    }
    if (solved) {
        cout << 1 << " " << countSwaps << endl;
    } else
        cout << 2 << endl;
    return 0;
}