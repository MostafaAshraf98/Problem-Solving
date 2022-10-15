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
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int row = matrix.size() + 1;
        int col = matrix[0].size() + 1;
        int count = 0;
        //Prefix Sum has an extra row and col at the beginning that is all zeros
        //Then the 2D prefix Sum matrix
        vector<vector<int>> prefixSum(row, vector<int>(col, 0));

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++) {
                prefixSum[i][j] =
                        prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }

        // We take the range of rows between r1 and r2 in the prefix sum matrix
        for (int r1 = 1; r1 < row; r1++)
            for (int r2 = r1; r2 < row; r2++) {
                // for every range of rows
                // Keys are the prefix sum so far and the value is the count
                unordered_map<int, int> mp;
                mp[0] = 1;
                // Loop over all the columns of prefix sum
                for (int c = 1; c < col; c++) {
                    // Curr sum is the sum of this subarray
                    int currSum = prefixSum[r2][c] - prefixSum[r1 - 1][c];
                    // leih badawar 3ala currSum - target?
                    // 3alashan law and el currSum = 8 and the target =1 fa ana badawar kan fih kam prefix abli 7
                    // leih keda 3alashan eli fel nos bein el etnin dool kan beyegma3 lel target eli howa wa7ed
                    // w di el number of submatrices eli el sum beta3ha kan el target
                    if (mp.find(currSum - target) != mp.end())
                        count += mp[currSum - target];

                    if (mp.find(currSum) == mp.end())
                        mp[currSum] = 1;
                    else
                        mp[currSum]++;
                }
            }
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