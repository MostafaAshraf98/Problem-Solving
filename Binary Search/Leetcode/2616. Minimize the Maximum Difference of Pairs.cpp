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
    // 000000000001111111111111
    // 1 means there is a difference less than or equal this, 0 ==> there is a different greater than this

    bool valid(const vector<int> &nums, const int p, int threshold)
    {
        int count = p;
        int i = 0;

        while (i <= nums.size() - 2 && count > 0)
        {
            if (nums[i + 1] - nums[i] <= threshold)
            {
                count--;
                i++;
            }
            i++;
        }

        if (count == 0)
            return true;

        return false;
    }
    int BS(const vector<int> &nums, const int p)
    {
        long start = 0;
        long end = 10e9;
        while (start < end)
        {
            long mid = start + (end - start) / 2;
            if (valid(nums, p, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        return BS(nums, p);
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
