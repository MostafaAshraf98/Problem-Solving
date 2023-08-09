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
    vector<vector<vector<double>>> memo;

    double solve(int remainingA, int remainingB, int index)
    {
        if (remainingA <= 0 && remainingB <= 0)
            return 0.5 * (1 / index);

        else if (remainingA <= 0)
            return 1 * (1 / index);

        else if (remainingB <= 0)
            return 0;

        if (memo[remainingA][remainingB][index] != -1)
            return memo[remainingA][remainingB][index];

        double result = 0;
        // take 4 servings from A and 0 from B
        result += solve(remainingA - 4, remainingB, index + 1);
        // take 3 servings from A and 1 from B
        result += solve(remainingA - 3, remainingB - 1, index + 1);

        // take 2 servings from A and 2 from B
        result += solve(remainingA - 2, remainingB - 2, index + 1);
        // take 1 serving from A and 3 from B
        result += solve(remainingA - 1, remainingB - 3, index + 1);

        return memo[remainingA][remainingB][index] = result;
    }

    double soupServings(int n)
    {
        n = ceil(n / 25);
        memo = vector<vector<vector<double>>>(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
        double result = solve(n, n, 0);
        return result;
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