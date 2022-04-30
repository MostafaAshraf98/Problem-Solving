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

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:

    int solve(vector<int> &prices, vector<vector<int>> &memo, int currentDayIndex, int currentHoldingIndex) {
        if (currentDayIndex == prices.size())
            return 0;

        if (memo[currentDayIndex][currentHoldingIndex] != -1)
            return memo[currentDayIndex][currentHoldingIndex];

        int buy = INT_MIN;
        int noBuyNorSell;
        int sell = INT_MIN;

        //buy if valid (valid if currentHoldingIndex ==-1) => not holding any at the moment
        if (currentHoldingIndex == prices.size())
            buy = solve(prices, memo, currentDayIndex + 1, currentDayIndex);

        //Sell if valid (valid if currentHoldingIndex!= -1 ) => already bought one, so we are holding one at the moment
        if (currentHoldingIndex != prices.size())
            sell = prices[currentDayIndex] - prices[currentHoldingIndex] +
                   solve(prices, memo, currentDayIndex + 1, prices.size());

        //No buy nor sell
        noBuyNorSell = solve(prices, memo, currentDayIndex + 1, currentHoldingIndex);

        return memo[currentDayIndex][currentHoldingIndex] = max(buy, max(sell, noBuyNorSell));
    }

    int maxProfit(vector<int> &prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(prices.size() + 1, -1));
        return solve(prices, memo, 0, prices.size());
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