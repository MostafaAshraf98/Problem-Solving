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

class Solution
{
public:
    int n;
    vector<vector<vector<double>>> memo;

    double solve(int currentRow, int currentCol, int remainingMoves)
    {
        // If it has moved outside the chess board then it should stop
        if (currentRow >= n || currentCol >= n || currentRow < 0 || currentCol < 0)
            return 0;

        if (remainingMoves == 0)
            return 1;

        if (memo[currentRow][currentCol][remainingMoves] != -1)
            return memo[currentRow][currentCol][remainingMoves];

        double answer = 0;
        // move up right
        answer += solve(currentRow - 2, currentCol + 1, remainingMoves - 1);

        // move right up
        answer += solve(currentRow - 1, currentCol + 2, remainingMoves - 1);

        // move right down
        answer += solve(currentRow + 1, currentCol + 2, remainingMoves - 1);

        // move down right
        answer += solve(currentRow + 2, currentCol + 1, remainingMoves - 1);

        // move down left
        answer += solve(currentRow + 2, currentCol - 1, remainingMoves - 1);

        // move left down
        answer += solve(currentRow + 1, currentCol - 2, remainingMoves - 1);

        // move left up
        answer += solve(currentRow - 1, currentCol - 2, remainingMoves - 1);

        // move up left
        answer += solve(currentRow - 2, currentCol - 1, remainingMoves - 1);

        return memo[currentRow][currentCol][remainingMoves] = answer;
    }

    double knightProbability(int n, int k, int row, int column)
    {
        this->n = n;
        memo = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        double count = solve(row, column, k);
        return count / pow(8, k);
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