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

// bottom up
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size() - 1; j >= 0; j--)
            {
                int moveBoth = INT_MIN;
                int moveFirst = INT_MIN;
                int moveSecond = INT_MIN;
                if (text1[i] == text2[j])
                    moveBoth = 1 + dp[i + 1][j + 1];
                else
                {
                    moveFirst = dp[i + 1][j];
                    moveSecond = dp[i][j + 1];
                }
                dp[i][j] = max(moveBoth, max(moveFirst, moveSecond));
            }
        }

        return dp[0][0];
    }
};

// top down
class Solution
{
public:
    string str1;
    string str2;
    vector<vector<int>> dp;

    int solve(int ptr1, int ptr2)
    {
        if (ptr1 == str1.size() || ptr2 == str2.size())
            return 0;

        if (dp[ptr1][ptr2] != -1)
            return dp[ptr1][ptr2];

        int moveBoth = INT_MIN;
        int moveFirst = INT_MIN;
        int moveSecond = INT_MIN;
        if (str1[ptr1] == str2[ptr2])
            moveBoth = 1 + solve(ptr1 + 1, ptr2 + 1);
        else
        {
            moveFirst = solve(ptr1 + 1, ptr2);
            moveSecond = solve(ptr1, ptr2 + 1);
        }
        return dp[ptr1][ptr2] = max(moveBoth, max(moveFirst, moveSecond));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        str1 = text1;
        str2 = text2;
        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
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