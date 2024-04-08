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
    int n;
    vector<int> dp;
    int solve(int currentIndex)
    {
        if (currentIndex == 0)
            return 0;
        if (currentIndex == 1)
            return 1;
        if (currentIndex == 2)
            return 1;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        return dp[currentIndex] = solve(currentIndex - 1) + solve(currentIndex - 2) + solve(currentIndex - 3);
    }

    int tribonacci(int n)
    {
        dp = vector<int>(n+1, -1);
        return solve(n);
    }
};

// bottom up
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        int one = 0;
        int two = 1;
        int three = 1;
        for (int i = 3; i <= n; i++)
        {
            int temp = three;
            three = one + two + three;
            one = two;
            two = temp;
        }
        return three;
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