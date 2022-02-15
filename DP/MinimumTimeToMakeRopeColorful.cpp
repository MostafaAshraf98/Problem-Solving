#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

class Solution {
public:

    int solve(string & colors, vector<int>& neededTime, vector<vector<int>> &memo, int index, char prevColor) {
        if (index == colors.size())
            return 0;

        if (index != 0 && memo[index][(int) prevColor] != -1)
            return memo[index][(int) prevColor];

        if (index != 0 && prevColor == colors[index])
            return memo[index][(int) prevColor] =
                           neededTime[index] + solve(colors, neededTime, memo, index + 1, prevColor);

        //There is two options .. remove it or leave it
        int remove = neededTime[index] + solve(colors, neededTime, memo, index + 1, prevColor);
        int leave = solve(colors, neededTime, memo, index + 1, colors[index]);
        return memo[index][(int) prevColor] = min(remove, leave);
    }

    int minCost(string colors, vector<int> &neededTime) {
        vector<vector<int>> memo(colors.size(), vector<int>(128, -1));
        return solve(colors, neededTime, memo, 0, '/');
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}