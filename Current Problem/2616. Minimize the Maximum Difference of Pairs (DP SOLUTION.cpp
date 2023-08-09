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

class Solution
{
public:
    vector<vector<int>> memo;

    int solve(const vector<int> &nums, int currentIndex, int p)
    {
        if (p == 0)
            return 0;

        if (currentIndex >= nums.size() - 1)
            return 10e5;

        if (memo[currentIndex][p] != -1)
            return memo[currentIndex][p];

        if ((nums.size() - currentIndex) / 2 < p)
            return 10e5;

        int take = max(abs(nums[currentIndex] - nums[currentIndex + 1]), solve(nums, currentIndex + 2, p - 1));

        int leave = solve(nums, currentIndex + 1, p);

        return memo[currentIndex][p] = min(take, leave);
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        memo = vector<vector<int>>(nums.size(), vector<int>(p + 1, -1));
        return solve(nums, 0, p);
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