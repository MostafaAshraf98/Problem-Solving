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
    bool find132pattern(vector<int> &nums)
    {
        vector<int> mins(nums.size(), 0);
        mins[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            mins[i] = min(nums[i], mins[i - 1]);

        stack<int> s;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (!s.empty() && s.top() < nums[i])
            {
                if (s.top() > mins[i])
                    return true;
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

// The idea of this problem is that we get the global min at each index. which means that at index i i get the min from the beginning of the array until index i
// then we use monostack, which mean a stack that is increasing only or decreasing, we start from the last index and move backwards.
// why does a monostack work? because we check all the elements that are less than current index (But the elements that are less than the global min
// will never work because it will also be less than the global min for a smaller index so we discard it to not process it more than once), if it is greater than the global min
// then the condition is satisfied and we return true. if it is not then it is less than the global min then we card discard this element and pop
// it from the stack keep only the current element at the top and the elements that are greater than it.

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}