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
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = nums[i] + prefixSum[i - 1];

        suffixSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixSum[i] = nums[i] + suffixSum[i + 1];

        for (int ptr1 = 0; ptr1 < n;ptr1++)
        {
            int currentSum = nums[ptr1];
            for(int ptr2)
        }
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