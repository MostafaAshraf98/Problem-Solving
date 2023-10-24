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

//Accepted
//DP

class Solution
{
public:
    unordered_map<string, bool> mp;
    vector<vector<int>> memo;
    string s;
    int solve(int start, int end)
    {
        if (end == s.size())
            return end - start;

        if (memo[start][end] != -1)
            return memo[start][end];

        string substring = s.substr(start, end - start + 1);

        int take = INT_MAX;
        if (mp.find(substring) != mp.end())
        {
            take = solve(end + 1, end + 1);
        }

        int leave = 1 + solve(start + 1, start + 1);
        int concat = solve(start, end + 1);

        return memo[start][end] = min(take, min(leave, concat));
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (string word : dictionary)
            mp[word] = true;

        this->s = s;
        memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
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