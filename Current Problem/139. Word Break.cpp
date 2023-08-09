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
    string s;
    unordered_map<string, bool> mp;
    int maxLength;
    vector<vector<int>> memo;

    bool solve(int startIndex, int endIndex)
    {
        if (startIndex == endIndex && startIndex == s.size())
            return true;
            
        if (endIndex == s.size())
            return false;

        if (memo[startIndex][endIndex] != -1)
            return memo[startIndex][endIndex];

        bool take = false;
        int length = endIndex - startIndex + 1;

        if (length > maxLength)
            return false;

        string substring = s.substr(startIndex, endIndex - startIndex + 1);

        if (mp.find(substring) != mp.end())
            take = solve(endIndex + 1, endIndex + 1);

        if (take)
            return true;

        bool leave = solve(startIndex, endIndex + 1);

        return memo[startIndex][endIndex] = leave;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        maxLength = -1;
        for (string word : wordDict)
        {
            mp[word] = true;
            int length = word.size();
            if (length > maxLength)
                maxLength = length;
        }
        memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        this->s = s;
        return solve(0, 0);
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