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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;

        vector<int> result;
        deque<pair<int, int>> q;

        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && q.back().second <= nums[i])
                q.pop_back();

            q.push_back({i, nums[i]});
        }

        int start = 0;
        int end = k - 1; // inclusive
        while (true)
        {
            result.push_back(q.front().second);

            start++;
            if (q.front().first < start)
                q.pop_front();

            end++;
            if (end == nums.size())
                break;
            while (!q.empty() && q.back().second <= nums[end])
                q.pop_back();

            q.push_back({end, nums[end]});
        }

        return result;
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