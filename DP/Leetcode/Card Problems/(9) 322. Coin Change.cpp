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

// top down
class Solution
{
public:
    vector<int> coins;
    vector<int> dp;

    int solve(int currentAmount)
    {
        if (currentAmount < 0)
            return -1;

        if (currentAmount == 0)
            return 0;

        if (dp[currentAmount] != -1)
            return dp[currentAmount];

        int best = INT_MAX;
        for (int coin : coins)
        {
            int result = solve(currentAmount - coin);
            if (result == -1)
                continue;
            best = min(best, 1 + result);
        }
        return dp[currentAmount] = best == INT_MAX ? -1 : best;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        this->coins = coins;
        dp = vector<int>(amount + 1, -1);
        return solve(amount);
    }
};

// bottom up
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
            return 0;

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i<=amount; i++)
            for (int coin : coins)
                if (coin <= i)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);

        return dp[amount] > amount ? -1 : dp[amount];
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