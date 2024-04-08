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

// top-down
class Solution
{
public:
    vector<vector<int>> memo;
    vector<int> coins;
    int solve(int currentIndex, int amount)
    {
        if (amount < 0 || currentIndex == coins.size())
            return 0;
        if (amount == 0)
            return 1;

        if (memo[currentIndex][amount] != -1)
            return memo[currentIndex][amount];

        int count = 0;
        count += solve(currentIndex, amount - coins[currentIndex]);
        count += solve(currentIndex + 1, amount);

        return memo[currentIndex][amount] = count;
    }

    int change(int amount, vector<int> &coins)
    {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, amount);
    }
};

// bottom up

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        for (int i = 0; i < coins.size(); i++)
            dp[i][0] = 1;
        for (int currentIndex = 0; currentIndex < coins.size(); currentIndex++)
        {
            for (int currentAmount = 1; currentAmount <= amount; currentAmount++)
            {
                int take = 0;
                int leave = 0;
                if (currentAmount - coins[currentIndex] >= 0)
                    take = dp[currentIndex][currentAmount - coins[currentIndex]];
                if (currentIndex != 0)
                    leave = dp[currentIndex - 1][currentAmount];
                dp[currentIndex][currentAmount] = take + leave;
            }
        }
        return dp[coins.size() - 1][amount];
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