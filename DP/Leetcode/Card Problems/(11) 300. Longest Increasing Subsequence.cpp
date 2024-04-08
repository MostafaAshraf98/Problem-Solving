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
    vector<int> dp;
    int n;
    int solve(int currentIndex)
    {
        if (currentIndex == n)
            return 0;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int best = 1;
        for (int i = currentIndex + 1; i < n; i++)
        {
            if (nums[i] > nums[currentIndex])
                best = max(best, 1 + solve(i));
        }

        return dp[currentIndex] = best;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        this->nums = nums;
        dp = vector<int>(n, -1);
        int best = 1;

        for (int i = 0; i < n; i++)
            best = max(best, solve(i));

        return best;
    }
};

// bottom up
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int best = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            best = max(best, dp[i]);
        }
        return best;
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