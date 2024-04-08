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

// Top down
class Solution
{
public:
    vector<int> prices;
    vector<vector<vector<int>>> dp;
    int n;
    int solve(int currentIndex, bool holding, bool coolDownDay)
    {
        if (currentIndex == n)
            return 0;

        if (dp[currentIndex][holding][coolDownDay] != -1)
            return dp[currentIndex][holding][coolDownDay];

        int doNothing = solve(currentIndex + 1, holding, false);
        int doSomething = INT_MIN;
        if (!coolDownDay)
        {
            if (holding)
                doSomething = prices[currentIndex] + solve(currentIndex + 1, false, true);
            else
                doSomething = -1 * prices[currentIndex] + solve(currentIndex + 1, true, false);
        }

        return dp[currentIndex][holding][coolDownDay] = max(doNothing, doSomething);
    }
    int maxProfit(vector<int> &prices)
    {
        this->prices = prices;
        n = prices.size();
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, 0, 0);
    }
};

// Bottom Up
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        for (int currentIndex = n - 1; currentIndex >= 0; currentIndex--)
        {
            for (int holding = 0; holding < 2; holding++)
            {
                for (int coolDown = 0; coolDown < 2; coolDown++)
                {
                    int doNothing = dp[currentIndex + 1][holding][false];
                    int doSomething = INT_MIN;
                    if (!coolDown)
                    {
                        if (holding)
                            doSomething = prices[currentIndex] + dp[currentIndex + 1][false][true];
                        else
                            doSomething = -1 * prices[currentIndex] + dp[currentIndex + 1][true][false];
                    }
                    dp[currentIndex][holding][coolDown] = max(doNothing, doSomething);
                }
            }
        }
        return dp[0][0][0];
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