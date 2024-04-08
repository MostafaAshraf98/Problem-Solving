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

// top down correct
class Solution
{
public:
    vector<vector<int>> dp;
    vector<int> hardestJob;
    vector<int> jobDifficulty;
    int d;
    int n;
    int solve(int currentJobIndex, int currentDay)
    {
        if (currentDay == d)
            return hardestJob[currentJobIndex];

        if (dp[currentJobIndex][currentDay] != -1)
            return dp[currentJobIndex][currentDay];
        int currentHardest = 0;
        int best = INT_MAX;
        for (int i = currentJobIndex; i < n - (d - currentDay); i++)
        {
            currentHardest = max(currentHardest, jobDifficulty[i]);
            int result = solve(i + 1, currentDay + 1);
            best = min(best, result + currentHardest);
        }
        return dp[currentJobIndex][currentDay] = best;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {

        this->d = d;
        this->n = jobDifficulty.size();
        this->jobDifficulty = jobDifficulty;

        if (n < d)
            return -1;

        dp = vector<vector<int>>(n, vector<int>(d + 1, -1));
        hardestJob = vector<int>(n);
        hardestJob[n - 1] = jobDifficulty[n - 1];
        for (int i = n - 2; i >= 0; i--)
            hardestJob[i] = max(hardestJob[i + 1], jobDifficulty[i]);

        return solve(0, 1);
    }
};

// bottom up
class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> dp(n, vector<int>(d + 1, INT_MAX));
        dp[n - 1][d] = jobDifficulty[n - 1];

        for (int i = n - 2; i >= 0; i--)
            dp[i][d] = max(jobDifficulty[i], dp[i + 1][d]);

        for (int currentDay = d - 1; currentDay >= 1; currentDay--)
        {
            for (int currentJobIndex = currentDay - 1; currentJobIndex < n - (d - currentDay); currentJobIndex++)
            {
                int currentHardest = 0;
                for (int i = currentJobIndex; i < n - (d - currentDay); i++)
                {
                    currentHardest = max(currentHardest, jobDifficulty[i]);
                    int result = dp[i + 1][currentDay + 1];
                    dp[currentJobIndex][currentDay] = min(dp[currentJobIndex][currentDay], result + currentHardest);
                }
            }
        }
        return dp[0][1];
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