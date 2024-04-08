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

// Accepted DP

class Solution
{
public:
    unordered_map<string, char> mp = {
        {"1", 'A'},
        {"2", 'B'},
        {"3", 'C'},
        {"4", 'D'},
        {"5", 'E'},
        {"6", 'F'},
        {"7", 'G'},
        {"8", 'H'},
        {"9", 'I'},
        {"10", 'J'},
        {"11", 'K'},
        {"12", 'L'},
        {"13", 'M'},
        {"14", 'N'},
        {"15", 'O'},
        {"16", 'P'},
        {"17", 'Q'},
        {"18", 'R'},
        {"19", 'S'},
        {"20", 'T'},
        {"21", 'U'},
        {"22", 'V'},
        {"23", 'W'},
        {"24", 'X'},
        {"25", 'Y'},
        {"26", 'Z'}};

    string s;
    vector<int> dp;
    int countWays(int currentIndex)
    {
        if (currentIndex == s.size() - 1 && s[currentIndex] == '0')
            return 0;

        if (currentIndex >= s.size() - 1)
            return 1;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int takeOne = 0;
        int takeTwo = 0;
        if (mp.find(string(1, s[currentIndex])) != mp.end())
            takeOne = countWays(currentIndex + 1);

        string twoDigits = s.substr(currentIndex, 2);
        if (mp.find(twoDigits) != mp.end())
            takeTwo = countWays(currentIndex + 2);

        return dp[currentIndex] = takeOne + takeTwo;
    }
    int numDecodings(string s)
    {
        this->s = s;
        dp = vector<int>(s.size(), -1);
        return countWays(0);
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