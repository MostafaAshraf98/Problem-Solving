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

// bottom up
class Solution
{
public:
    vector<int> cost;
    vector<int> dp;

    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 0)
            return 0;
        if (cost.size() == 1)
            return cost[0];

        cost.push_back(0);
        dp = vector<int>(cost.size(), -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int oneStep = dp[i - 1] + cost[i];
            int twoStep = dp[i - 2] + cost[i];
            dp[i] = min(oneStep, twoStep);
        }
        return dp[cost.size() - 1];
    }
};

// top down
class Solution
{
public:
    vector<int> cost;
    vector<int> dp;

    int solve(int currentIndex)
    {
        if (currentIndex == 0)
            return cost[0];
        if (currentIndex == 1)
            return cost[1];

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int oneStep = cost[currentIndex] + solve(currentIndex - 1);
        int twoStep = cost[currentIndex] + solve(currentIndex - 2);

        return dp[currentIndex] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.push_back(0);
        dp = vector<int>(cost.size(), -1);
        this->cost = cost;
        return solve(cost.size() - 1);
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