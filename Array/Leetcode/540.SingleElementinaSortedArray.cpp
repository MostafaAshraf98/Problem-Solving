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

//https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) // if there is only 1 element
            return nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i += 2) {
            if (prev != nums[i]) // if in this pair ... the first is not equal the second
                return prev;
            if (i + 1 < nums.size() - 1) // if there are still pairs
                prev = nums[i + 1];
            else if (i + 1 == nums.size() - 1) // if this is a single element in a pair
                return nums[i + 1];
        }
        return 0; // this line will never get executed
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