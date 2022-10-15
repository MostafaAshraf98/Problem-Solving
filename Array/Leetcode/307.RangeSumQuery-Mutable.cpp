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

class NumArray {
public:
    vector<int> nums;
    vector<int> blocks; // keeps the sum of each block
    int len; // the size of the blocks vector

    NumArray(vector<int> &nums) {
        this->nums = nums;
        len = (int) ceil(sqrt(nums.size()));
        for (int i = 0; i < len; i++)
            blocks.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            blocks[i / len] += nums[i];
        }
    }

    void update(int index, int val) {
        int block = index / len;
        blocks[block] -= nums[index] - val;
        nums[index] = val;

    }

    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / len;
        int endBlock = right / len;
        if (startBlock == endBlock) {
            for (int i = left; i <= right; i++)
                sum += nums[i];
        } else {
            for (int i = left; i <= (startBlock + 1) * len - 1; i++)
                sum += nums[i];
            for (int i = startBlock+1; i <= endBlock-1; i++)
                sum += blocks[i];
            for (int i = endBlock * len; i <= right; i++)
                sum += nums[i];

        }
        return sum;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}