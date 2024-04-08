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
// Greedy

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        int currentAvailableJumps = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            currentAvailableJumps = max(currentAvailableJumps, nums[i]);
            if (currentAvailableJumps == 0)
                return false;
            currentAvailableJumps--;
        }
        return true;
    }
};

// Accepted DP
// Top Down
class Solution
{
public:
    vector<int> nums;
    vector<int> dp;
    int n;
    bool solve(int currentIndex)
    {
        if (currentIndex >= n - 1)
            return true;

        if (dp[currentIndex] != -1)
            return false;

        for (int i = currentIndex + 1; i <= currentIndex + nums[currentIndex]; i++)
        {
            bool result = solve(i);
            if (result)
                return true;
        }
        return dp[currentIndex] = false;
    }
    bool canJump(vector<int> &nums)
    {
        n = nums.size();
        this->nums = nums;
        dp = vector<int>(n, -1);
        return solve(0);
    }
};

// DP Bottom Up 1

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j <= i + nums[i]; j++)
            {
                if (j >= n - 1 || dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

// DP Bottom Up 2
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        if (nums[0] == 0)
            return false;
        int n = nums.size();
        vector<int> dp(n, false);
        dp[0] = true;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
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