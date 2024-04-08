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
    vector<int> cost;
    vector<int> dp;
    int n;
    int solve(int currentIndex)
    {
        if (currentIndex >= n)
            return 0;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int next = solve(currentIndex + 1);
        int afterNext = solve(currentIndex + 2);

        return dp[currentIndex] = cost[currentIndex] + min(next, afterNext);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        this->cost = cost;
        n = cost.size();
        dp = vector<int>(n, -1);
        return min(solve(0), solve(1));
    }
};

// bottom up
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n <= 1)
            return min(cost[0], cost[1]);
            
        int oneBack = 0;
        int twoBack = 0;
        for (int i = 2; i <= n; i++)
        {
            int temp = oneBack;
            oneBack = min(cost[i - 1] + oneBack, cost[i - 2] + twoBack);
            twoBack = temp;
        }
        return oneBack;
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