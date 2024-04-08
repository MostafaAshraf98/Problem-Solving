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
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}};
    vector<vector<int>> dp;
    const long long MOD = 1e9 + 7;

    int solve(int square, int remaining)
    {
        if (remaining == 0)
            return 1;

        if (dp[square][remaining] != -1)
            return dp[square][remaining];

        int result = 0;
        for (int jump : jumps[square])
            result = (result + solve(jump, remaining - 1)) % MOD;

        return dp[square][remaining] = result;
    }
    int knightDialer(int n)
    {
        dp = vector<vector<int>>(10, vector<int>(n, -1));
        int result = 0;
        for (int square = 0; square < 10; square++)
            result = (result + solve(square, n - 1)) % MOD;
        return result;
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