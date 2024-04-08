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
    vector<vector<int>> memo;
    int solve(const vector<int> &perfectSquares, int remaining, int currentIndex)
    {
        if (remaining == 0)
            return 0;
        if (remaining < 0 || currentIndex == -1)
            return 10e8;

        if (memo[remaining][currentIndex] != -1)
            return memo[remaining][currentIndex];

        int take = 1 + solve(perfectSquares, remaining - perfectSquares[currentIndex], currentIndex);

        int leave = solve(perfectSquares, remaining, currentIndex - 1);

        return memo[remaining][currentIndex] = min(take, leave);
    }
    int numSquares(int n)
    {
        vector<int> perfectSquares;
        for (int i = 1; i <= sqrt(n); i++)
            perfectSquares.push_back(pow(i, 2));
        memo = vector<vector<int>>(n + 1, vector<int>(perfectSquares.size(), -1));
        return solve(perfectSquares, n, perfectSquares.size() - 1);
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