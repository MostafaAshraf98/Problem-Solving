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
    vector<int> nums;
    vector<vector<vector<pair<int, int>>>> memo;

    pair<long, long> solve(int itStart, int itEnd, bool currentTurn)
    {
        if (itStart == itEnd)
        {
            if (currentTurn == 0)
                return make_pair(nums[itStart], 0);
            else
                return make_pair(0, nums[itStart]);
        }

        if (memo[itStart][itEnd][currentTurn].first != -1)
            return memo[itStart][itEnd][currentTurn];

        pair<long, long> takeStart;
        pair<long, long> takeEnd;

        takeStart = solve(itStart + 1, itEnd, !currentTurn);
        takeEnd = solve(itStart, itEnd - 1, !currentTurn);

        if (currentTurn == 0)
        {
            takeStart.first += nums[itStart];
            takeEnd.first += nums[itEnd];
        }
        else
        {
            takeStart.second += nums[itStart];
            takeEnd.second += nums[itEnd];
        }

        if ((takeStart.first >= takeEnd.first) && currentTurn == 0)
            return memo[itStart][itEnd][currentTurn] = takeStart;

        else if ((takeStart.first < takeEnd.first) && currentTurn == 0)
            return memo[itStart][itEnd][currentTurn] = takeEnd;

        else if ((takeStart.second >= takeEnd.second) && currentTurn == 1)
            return memo[itStart][itEnd][currentTurn] = takeStart;

        else
            return memo[itStart][itEnd][currentTurn] = takeEnd;
    }

    bool PredictTheWinner(vector<int> &nums)
    {
        this->nums = nums;
        memo = vector<vector<vector<pair<int, int>>>>(nums.size(), vector<vector<pair<int, int>>>(nums.size(), vector<pair<int, int>>(2, make_pair(-1, -1))));
        pair<int, int> result = solve(0, nums.size() - 1, 0);

        if (result.first >= result.second)
            return true;
        return false;
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