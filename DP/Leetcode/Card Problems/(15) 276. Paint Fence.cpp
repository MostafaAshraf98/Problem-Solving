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

// top down
class Solution
{
public:
    int n;
    int k;
    vector<int> dp;
    int solve(int currentIndex)
    {
        if (currentIndex == 0)
            return k;
        if (currentIndex == 1)
            return k * k;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        return dp[currentIndex] = (k - 1) * (solve(currentIndex - 1) + solve(currentIndex - 2));
    }
    int numWays(int n, int k)
    {
        this->n = n;
        this->k = k;
        dp = vector<int>(n, -1);
        return solve(n - 1);
    }
};

// bottom up
class Solution
{
public:
    int numWays(int n, int k)
    {

        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        int twoBack = k;
        int oneBack = k * k;
        for (int i = 2; i < n; i++)
        {
            int curr = (k - 1) * (oneBack + twoBack);
            twoBack = oneBack;
            oneBack = curr;
        }
        return oneBack;
    }
};

// How many ways there are to paint the ith post: There are 2 options:
// 1- Use different color than the previous post: there are (k-1) colors for us to use.
// Totalways(i) = (k-1) * totalWays(i-1) -- Different Colors
// 2- Use same color as previous post: to find the number of ways to paint it with the same color as the previous post
// without breaking the restriction, we need to find the number of ways the previous post has different color than i-2 post
// to find this number. we apply the equation we used in 1 for i-1 post 
// we get TotalWays(i-1) = (k-1) * totalWays(i-2)
// Combining (1) and (2) we get:
// TotalWays(i) = (k-1) * totalWays(i-1) + (k-1) * totalWays(i-2)
// Simplify => TotalWays(i) = (k-1) (totalWays(i-1) * totalWays(i-2))

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}