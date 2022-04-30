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
    const int mod = 1e9 + 7;
public:
    int solve(vector<vector<vector<int>>> &memo, int row, int col, int remainingMoves) {
        if (row < 0 || row > 3 || col < 0 || col > 2 || (row == 3 && col == 0) || (row == 3 && col == 2))
            return 0;

        if (remainingMoves == 0)
            return 1;

        if (memo[remainingMoves][row][col] != -1)
            return memo[remainingMoves][row][col];


        int sum = 0;
        //move up left
        int m1 = solve(memo, row - 2, col - 1, remainingMoves - 1);
        sum = (sum + m1) % mod;

        //move up right
        int m2 = solve(memo, row - 2, col + 1, remainingMoves - 1);
        sum = (sum + m2) % mod;

        //move right up
        int m3 = solve(memo, row - 1, col + 2, remainingMoves - 1);
        sum = (sum + m3) % mod;


        //move right down
        int m4 = solve(memo, row + 1, col + 2, remainingMoves - 1);
        sum = (sum + m4) % mod;

        //move down right
        int m5 = solve(memo, row + 2, col + 1, remainingMoves - 1);
        sum = (sum + m5) % mod;

        //move down left
        int m6 = solve(memo, row + 2, col - 1, remainingMoves - 1);
        sum = (sum + m6) % mod;

        //move left up
        int m7 = solve(memo, row - 1, col - 2, remainingMoves - 1);
        sum = (sum + m7) % mod;

        //move left down
        int m8 = solve(memo, row + 1, col - 2, remainingMoves - 1);
        sum = (sum + m8) % mod;

        return memo[remainingMoves][row][col] = sum;
    }

    int knightDialer(int n) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(4, vector<int>(3, -1)));
        int result = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                result = (result + solve(memo, i, j, n - 1)) % mod;
        return result;

    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    Solution s;
    cout << s.knightDialer(3131) << endl;
    return 0;
}