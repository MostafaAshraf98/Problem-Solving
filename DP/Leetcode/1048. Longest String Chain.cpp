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
// DP

class Solution
{
public:
    unordered_map<string, int> memo;
    unordered_map<string, bool> mp;

    int solve(string currentWord)
    {
        if (mp.find(currentWord) == mp.end())
            return 0;

        if (memo.find(currentWord) != memo.end())
            return memo[currentWord];

        int currentMax = 1;
        for (int i = 0; i < currentWord.size(); i++)
        {
            string temp = currentWord;
            currentWord.erase(i, 1);
            int result = 1 + solve(currentWord);
            currentMax = max(currentMax, result);
            currentWord = temp;
        }
        return memo[currentWord] = currentMax;
    }
    int longestStrChain(vector<string> &words)
    {
        for(string word: words)
            mp[word] = true;

        int maxResult = 1;
        for(string word: words)
        {
            int result = solve(word);
            maxResult = max(maxResult, result);
        }
        return maxResult;
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