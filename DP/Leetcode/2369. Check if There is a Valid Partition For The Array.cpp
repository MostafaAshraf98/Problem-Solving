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

bool increasingSeq(const vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] != nums[i - 1] + 1)
            return false;

    return true;
}

class Solution
{
public:
    bool solve(const vector<int> &nums, int currentIndex, vector<int> currentArray)
    {
        int size = currentArray.size();
        bool incSeq = increasingSeq(currentArray);

        if (size == 4)
            return false;

        if (currentIndex == nums.size() && ((size >= 2 && !incSeq) || size == 3 && incSeq))
            return true;
        else if (currentIndex == nums.size())
            return false;

        int lastElement = currentArray[currentArray.size() - 1];
        int currentElement = nums[currentIndex];

        // take it into current Array if possible
        bool take = false;
        if (currentElement == lastElement || (incSeq && currentElement == lastElement + 1))
        {
            currentArray.push_back(currentElement);
            take = solve(nums, currentIndex + 1, currentArray);
            currentArray.pop_back();
        }

        if (take)
            return take;

        // start a new array with it
        bool start = false;
        if ((currentArray.size() > 1 && !incSeq) || (size == 3 && incSeq))
        {
            currentArray = vector<int>();
            currentArray.push_back(currentElement);
            start = solve(nums, currentIndex + 1, currentArray);
        }

        return take || start;
    }
    bool validPartition(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return false;

        sort(nums.begin(), nums.end());

        vector<int> currentArray;
        currentArray.push_back(nums[0]);

        return solve(nums, 1, currentArray);
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