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

// Bottom Up
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
            
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            int leave = dp[i - 1];
            int take = dp[i - 2] + nums[i];
            dp[i] = max(take, leave);
        }
        return dp[nums.size() - 1];
    }
};

// Top down

class Solution
{
public:
    vector<int> nums;
    vector<int> dp;
    int solve(int currentIndex)
    {
        if (currentIndex == 0)
            return nums[0];

        if (currentIndex == 1)
            return max(nums[0], nums[1]);

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int take = nums[currentIndex] + solve(currentIndex - 2);

        int leave = solve(currentIndex - 1);

        return dp[currentIndex] = max(take, leave);
    }

    int rob(vector<int> &nums)
    {
        this->nums = nums;
        dp = vector<int>(nums.size(), -1);
        return solve(nums.size() - 1);
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