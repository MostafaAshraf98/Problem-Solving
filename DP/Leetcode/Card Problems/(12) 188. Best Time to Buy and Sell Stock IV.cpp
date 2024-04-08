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
    int n;
    vector<int> prices;
    vector<vector<vector<int>>> dp;
    int solve(int currentIndex, int remainingTransactions, bool shouldSell)
    {
        if (currentIndex == n || remainingTransactions == 0)
            return 0;

        if (dp[currentIndex][remainingTransactions][shouldSell] != -1)
            return dp[currentIndex][remainingTransactions][shouldSell];

        int doSomething = INT_MIN;
        int doNothing = INT_MIN;

        if (shouldSell)
            doSomething = prices[currentIndex] + solve(currentIndex + 1, remainingTransactions - 1, false);
        else
            doSomething = -1 * prices[currentIndex] + solve(currentIndex + 1, remainingTransactions, true);

        doNothing = solve(currentIndex + 1, remainingTransactions, shouldSell);

        return dp[currentIndex][remainingTransactions][shouldSell] = max(doSomething, doNothing);
    }
    int maxProfit(int k, vector<int> &prices)
    {
        n = prices.size();
        this->prices = prices;
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(0, k, false);
    }
};

// bottom up
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1 || k == 0)
            return 0;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int currentIndex = n - 1; currentIndex >= 0; currentIndex--)
        {
            for (int remainingTrans = k; remainingTrans > 0; remainingTrans--)
            {
                for (int shouldSell = 0; shouldSell < 2; shouldSell++)
                {
                    int doNothing = dp[currentIndex + 1][remainingTrans][shouldSell];
                    int doSomething = INT_MIN;
                    if (shouldSell)
                        doSomething = prices[currentIndex] + dp[currentIndex + 1][remainingTrans - 1][false];
                    else
                        doSomething = -prices[currentIndex] + dp[currentIndex + 1][remainingTrans][true];

                    dp[currentIndex][remainingTrans][shouldSell] = max(doNothing, doSomething);
                }
            }
        }
        return dp[0][k][0];
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