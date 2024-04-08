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
    vector<int> nums;
    vector<int> multipliers;
    vector<vector<int>> dp;
    int n;
    int m;

    int solve(int left, int multIndex)
    {
        int right = n - 1 - (multIndex - left);

        if (multIndex == m)
            return 0;

        if (dp[multIndex][left] != -1)
            return dp[multIndex][left];

        int takeRight = nums[right] * multipliers[multIndex] + solve(left, multIndex + 1);
        int takeLeft = nums[left] * multipliers[multIndex] + solve(left + 1, multIndex + 1);

        return dp[multIndex][left] = max(takeRight, takeLeft);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        this->n = nums.size();
        this->m = multipliers.size();

        this->nums = nums;
        this->multipliers = multipliers;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return solve(0, 0);
    }
};

// bottom up
class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        
        for (int multIndex = m - 1; multIndex >= 0; multIndex--) // multiplier
        {
            for (int left = multIndex; left >= 0; left--) // left
            {
                int right = n - 1 - (multIndex - left);
                int takeRight = nums[right] * multipliers[multIndex] + dp[multIndex + 1][left];
                int takeLeft = nums[left] * multipliers[multIndex] + dp[multIndex + 1][left + 1];
                dp[multIndex][left] = max(takeRight, takeLeft);
            }
        }
        return dp[0][0];
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