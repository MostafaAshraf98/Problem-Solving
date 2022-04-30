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

//https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];
        for (int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                } else
                    dp[i][j] = 0;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                count += dp[i][j];
        return count;
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