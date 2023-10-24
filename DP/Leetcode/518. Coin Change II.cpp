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
    int solve(const vector<int> &coins, int currentIndex, int remainingAmount)
    {
        if (remainingAmount == 0)
            return 1;
        if (remainingAmount < 0)
            return 0;
        if (currentIndex >= coins.size())
            return 0;

        if (memo[currentIndex][remainingAmount] != -1)
            return memo[currentIndex][remainingAmount];

        // take
        int take = solve(coins, currentIndex, remainingAmount - coins[currentIndex]);

        int leave = solve(coins, currentIndex + 1, remainingAmount);

        return memo[currentIndex][remainingAmount] = take + leave;
    }
    int change(int amount, vector<int> &coins)
    {
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, 0, amount);
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