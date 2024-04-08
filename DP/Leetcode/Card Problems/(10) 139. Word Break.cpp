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

// top down
class Solution
{
public:
    string s;
    vector<string> wordDict;
    vector<int> dp;
    bool solve(int currentIndex)
    {
        if (currentIndex == s.size())
            return true;

        if (dp[currentIndex] != -1)
            return false;

        bool answer = false;
        for (string word : wordDict)
        {
            string sub = s.substr(currentIndex, word.size());
            if (word == sub)
                answer = solve(currentIndex + word.size());
            if (answer)
                return true;
        }
        return dp[currentIndex] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        this->s = s;
        this->wordDict = wordDict;
        dp = vector<int>(s.size(), -1);
        return solve(0);
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int start = n - 1; start >= 0; start--)
        {

            for (string word : wordDict)
            {
                string sub = s.substr(start, word.size());
                if (sub == word)
                    dp[start] = dp[start] || dp[start + word.size()];
            }
        }
        return dp[0];
    }
};

class Solution
{
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (string word : wordDict)
            {
                if (i >= word.size())
                {
                    string str = s.substr(i - word.size(), word.size());
                    if (str == word)
                        dp[i] = dp[i - word.size()];
                }
            }
        }
        return dp[s.size()];
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