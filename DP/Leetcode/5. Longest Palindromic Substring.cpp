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
    string longestPalindrome(string s)
    {
        int n = s.size();

        if (n <= 1)
            return s;

        pair<int, int> ans;
        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;

            if (i != n - 1)
            {
                if (s[i] == s[i + 1])
                {
                    dp[i][i + 1] = true;
                    ans = {i, i + 1};
                }
            }
        }

        for (int diff = 2; diff < n; diff++)
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = i + diff;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }
        return s.substr(ans.first, ans.second - ans.first + 1);
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