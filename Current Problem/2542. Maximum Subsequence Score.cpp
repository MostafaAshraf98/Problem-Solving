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

// class Solution
// {
// public:
//     vector<vector<pair<int, int>>> memo;

//     pair<int, int> solve(const vector<int> &nums1, const vector<int> &nums2, int currentIndex, int remaining)
//     {
//         if (remaining == 0)
//             return {0, INT_MAX};

//         if (currentIndex == nums1.size())
//             return {INT_MIN, 0};

//         if (memo[currentIndex][remaining].first != -1)
//             return memo[currentIndex][remaining];
//         // take
//         pair<long long, int> take = solve(nums1, nums2, currentIndex + 1, remaining - 1);
//         take.first += nums1[currentIndex];
//         take.second = min(take.second, nums2[currentIndex]);

//         // leave
//         pair<long long, int> leave = solve(nums1, nums2, currentIndex + 1, remaining);

//         return memo[currentIndex][remaining] = take.first * take.second >= leave.first * leave.second ? take : leave;
//     }
//     long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
//     {
//         memo = vector<vector<pair<int, int>>>(nums1.size(), vector<pair<int, int>>(k + 1, {-1, -1}));
//         pair<long long, int> p = solve(nums1, nums2, 0, k);
//         return p.first * p.second;
//     }
// };
class Solution
{
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<pair<long long, int>>> dp = vector<vector<pair<long long, int>>>(nums1.size(), vector<pair<long long, int>>(k + 1, {-1, -1}));
        for (int i = 0; i < nums1.size(); i++)
            dp[i][1] = {nums1[i], nums2[i]};

        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 2; i <= k; j++)
            {
                // take
                pair<long long, int> take = {nums1[i] + dp[i - 1][j - 1].first, min(nums2[i], dp[i - 1][j - 1].second)};

                // leave
                pair<long long, int> leave = {dp[i - 1][j].first, dp[i - 1][j].second};

                dp[i][j] = take.first * take.second >= leave.first * leave.second ? take : leave;
            }
        }
        pair<long long, int> ans = dp[nums1.size() - 1][k];
        return ans.first * ans.second;
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