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

class Solution
{
public:
    unordered_map<int, bool> mp;
    int lastStone;
    vector<unordered_map<int, bool>> memo;
    bool solve(int currentStone, int k)
    {
        if (currentStone == lastStone)
            return true;

        if (memo[k].find(currentStone) != memo[k].end())
            return false;

        bool jumpK = false;
        bool jumpKMinus1 = false;
        bool jumpKPlus1 = false;
        if (mp.find(currentStone + k) != mp.end())
            jumpK = solve(currentStone + k, k);

        if (jumpK)
            return jumpK;

        if (mp.find(currentStone + k + 1) != mp.end())
            jumpKPlus1 = solve(currentStone + k + 1, k + 1);

        if (jumpKPlus1)
            return jumpKPlus1;

        if (mp.find(currentStone + k - 1) != mp.end() && k != 1)
            jumpKMinus1 = solve(currentStone + k - 1, k - 1);

        return memo[k][currentStone] = jumpKMinus1;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones.size() == 1)
            return true;

        if (stones[1] - stones[0] != 1)
            return false;

        for (int stone : stones)
            mp[stone] = true;

        lastStone = stones[stones.size() - 1];
        memo = vector<unordered_map<int, bool>>(stones.size() + 2);
        return solve(stones[1], 1);
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