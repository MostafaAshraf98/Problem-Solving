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
    unordered_map<string, string> mp;
    string getReversed(const string &num, int currentIndex)
    {
        if (currentIndex == num.size())
            return "";

        string sub = num.substr(currentIndex, num.size() - currentIndex);
        if (mp.find(sub) != mp.end())
            return mp[sub];

        string result = getReversed(num, currentIndex + 1) + num[currentIndex];
        return mp[sub] = result;
    }
    int countNicePairs(vector<int> &nums)
    {
        long long modulusConstant = static_cast<long long>(10e9 + 7);
        long long result = 0;
        for (int num : nums)
            getReversed(to_string(num), 0);

        unordered_map<int, long long> convertedMap;
        for (int num : nums)
            convertedMap[num] = stol(mp[to_string(num)]);

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + convertedMap[nums[j]] == nums[j] + convertedMap[nums[i]])
                    result++;

        return result % modulusConstant;
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