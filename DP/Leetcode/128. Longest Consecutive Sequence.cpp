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
// MAP and DP

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        unordered_map<int, bool> mp;
        unordered_map<int, int> memo;
        int result = 0;

        for (int num : nums)
            mp[num] = false;

        for (auto it : mp)
        {
            if (it.second)
                continue;

            mp[it.first] = true;

            int currentLength = 1;
            int currentVal = it.first + 1;

            while (true)
            {
                if (mp.find(currentVal) != mp.end())
                {
                    if (mp[currentVal])
                    {
                        currentLength += memo[currentVal];
                        break;
                    }
                    mp[currentVal] = true;
                    currentLength++;
                    currentVal++;
                }
                else
                    break;
            }

            if (currentLength > result)
                result = currentLength;

            memo[it.first] = currentLength;
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