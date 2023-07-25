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
    vector<int> memo;
    vector<int> nums;
    vector<int> countLIS;
    int count = 0;
    int overallLIS = 1;

    int LIS(int lastIndex)
    {
        if (memo[lastIndex] != -1)
            return memo[lastIndex];

        int longestSub = 1;
        int countLongest = 0;
        for (int i = 0; i < lastIndex; i++)
        {
            if (nums[i] < nums[lastIndex])
            {
                int sub = LIS(i) + 1;
                if (sub > overallLIS)
                {
                    overallLIS = sub;
                    count = 1;
                }
                else if (sub == overallLIS)
                    count++;

                if (longestSub == sub)
                    countLongest += countLIS[i];

                else if (longestSub < sub)
                {
                    longestSub = sub;
                    countLongest = countLIS[i];
                }
            }
        }
        if (longestSub == 1 && overallLIS == 1)
            count++;

        return memo[lastIndex] = longestSub;
    }
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        else if (nums.size() == 1)
            return 1;

        memo = vector<int>(nums.size(), -1);
        countLIS = vector<int>(nums.size(), -1);
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++)
            LIS(i);
        return count;
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