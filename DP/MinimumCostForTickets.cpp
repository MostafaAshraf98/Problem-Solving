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

class Solution {
public:

    int solve(vector<int> &days, vector<int> &costs, vector<vector<int>> &memo, int index, int expiryDate) {
        if (index == days.size())
            return 0;

        if (memo[index][expiryDate] != -1)
            return memo[index][expiryDate];

        //for each valid option do recurse undo
        //if there still time in the last bought ticket then we should not
        if (expiryDate >= days[index])
            return memo[index][expiryDate] = solve(days, costs, memo, index + 1, expiryDate);

        //else the expiry date
        int buy1 = costs[0] + solve(days, costs, memo, index + 1, days[index]);
        int buy7 = costs[1] + solve(days, costs, memo, index + 1, days[index] + 6);
        int buy30 = costs[2] + solve(days, costs, memo, index + 1, days[index] + 29);

        return memo[index][expiryDate] = min(min(buy1, buy7), buy30);

    }

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<vector<int>> memo(days.size(), vector<int>(400, -1));
        return solve(days, costs, memo, 0, 0);
    }
};


#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}