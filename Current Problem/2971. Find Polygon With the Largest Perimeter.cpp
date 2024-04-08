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
    long long largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for (int i = n - 1; i >= 2; i--)
        {
            if (prefixSum[i - 1] > nums[i])
                return prefixSum[i - 1] + nums[i];
        }
        return -1;
    }
};

// Calculate the prefix sum for every index.
// i want to take the largest sum possible so i check the largest possible index that satisfy the condition:
// exists a sum from the other elements that is greater than it
// sum of other element is prefixSum[i-1] that must be greater than it.
// if it is satisfied then we return this prefix sum + the length of this side which is equal to the total length of the polygon
// a polygon consists of at least 3 sides that is why the for look is till i>=2 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}