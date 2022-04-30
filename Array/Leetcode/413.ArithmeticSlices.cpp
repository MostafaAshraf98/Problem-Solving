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

    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3)
            return 0;
        int totalCount = 0;
        int currentDifference = nums[1] - nums[0];
        int countcurrentElements = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == currentDifference)
                countcurrentElements++;
            else {
                if (countcurrentElements >= 3)
                    totalCount += ((countcurrentElements - 2) * (countcurrentElements - 1)) / 2;
                countcurrentElements = 2;
                currentDifference = nums[i] - nums[i - 1];
            }
        }
        if (countcurrentElements >= 3) {
            totalCount += ((countcurrentElements - 2) * (countcurrentElements - 1)) / 2;
        }
        return totalCount;
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