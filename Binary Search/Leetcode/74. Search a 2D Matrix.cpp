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
// 1111110000000
//  where 0 is greater and 1 is less than or equal

class Solution
{
public:
    int BS(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start + 1) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid;
        }
        return start;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (matrix[0][0] > target || matrix[n - 1][m - 1] < target)
            return false;

        vector<int> firstCol;

        for (int i = 0; i < n; i++)
            firstCol.push_back(matrix[i][0]);

        int row = BS(firstCol, target);
        int col = BS(matrix[row], target);

        if (matrix[row][col] == target)
            return true;

        return false;
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