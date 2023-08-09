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

//00000011111111
//0 is greater than or equal and 1 is less than

// 0000000001111111
//  0 is less than, 1 is greater than or equal
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;

        if (nums[0] > target && nums[nums.size() - 1] < target)
            return -1;

        int start = 0;
        int end = nums.size() - 1;

        while (start != end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= nums[0])
                start = mid + 1;
            else
                end = mid;
        }

        int pivotIndex = start;

        if (nums[0] > target)
        {
            start = pivotIndex;
            end = nums.size() - 1;
        }
        else
        {
            start = 0;
            end = pivotIndex - 1;
        }

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        if (nums[start] == target)
            return start;
        return -1;
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