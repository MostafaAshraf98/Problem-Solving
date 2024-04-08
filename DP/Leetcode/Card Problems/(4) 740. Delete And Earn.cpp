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
    unordered_map<int, int> mp;
    vector<int> uniques;
    vector<int> dp;
    int solve(int currentIndex)
    {
        int value = uniques[currentIndex];
        int count = mp[value];

        if (currentIndex == 0)
            return count * value;

        if (currentIndex == 1)
        {
            int valueZero = uniques[0];
            int countZero = mp[valueZero];

            if (valueZero != value - 1)
                return count * value + countZero * valueZero;

            return max(count * value, countZero * valueZero);
        }

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int take = 0;
        if (uniques[currentIndex - 1] == value - 1)
            take = value * count + solve(currentIndex - 2);
        else
            take = value * count + solve(currentIndex - 1);

        int leave = solve(currentIndex - 1);

        return dp[currentIndex] = max(take, leave);
    }

    int deleteAndEarn(vector<int> &nums)
    {
        dp = vector<int>(nums.size(), -1);
        for (int num : nums)
        {
            if (mp.find(num) == mp.end())
                mp[num] = 1;
            else
                mp[num]++;
        }

        for (auto it : mp)
            uniques.push_back(it.first);

        sort(uniques.begin(), uniques.end());
        return solve(uniques.size() - 1);
    }
};

// bottom up
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> uniques;

        for (int num : nums)
        {
            if (mp.find(num) == mp.end())
                mp[num] = 1;
            else
                mp[num]++;
        }

        for (auto it : mp)
            uniques.push_back(it.first);

        sort(uniques.begin(), uniques.end());
        vector<int> dp(uniques.size(), -1);

        if (uniques.size() == 1)
            return uniques[0] * mp[uniques[0]];

        dp[0] = uniques[0] * mp[uniques[0]];

        if (uniques[0] == uniques[1] - 1)
            dp[1] = max(dp[0], uniques[1] * mp[uniques[1]]);
        else
            dp[1] = dp[0] + uniques[1] * mp[uniques[1]];

        for (int i = 2; i < uniques.size(); i++)
        {
            int take = uniques[i] * mp[uniques[i]];

            if (uniques[i] == uniques[i - 1] + 1)
                take += dp[i - 2];
            else
                take += dp[i - 1];

            int leave = dp[i - 1];
            dp[i] = max(take, leave);
        }
        return dp[dp.size() - 1];
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