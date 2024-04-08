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

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        vector<vector<int>> EDS(n, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            vector<int> maxSubset;

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && maxSubset.size() < EDS[j].size())
                    maxSubset = EDS[j];
            }
            maxSubset.push_back(nums[i]);
            EDS[i] = maxSubset;
        }
        vector<int> answer;
        for (auto set : EDS)
            if (set.size() > answer.size())
                answer = set;
        return answer;
    }
};

// First we sort the array use the fact that if x % y ==0 and y % z ==0 then x%z == 0 we only to check the largest element in EDS
// EDS (Divisible subsets) the index of this array is the index in nums for the largest element in this set.
// for every number i loop over all the previous number and take the largest set for which its largest number divides my current number
// and appending to this my current number is the EDS of this currentNumber

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}