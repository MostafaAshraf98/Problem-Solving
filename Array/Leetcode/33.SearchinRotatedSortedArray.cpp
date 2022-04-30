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

//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {

public:

// returns the index of pivot
// 00001111
// 1 if it is less than the first element
// we try to get the index of the element that is the smallest than the first element
    int BS1(vector<int> &nums, int st, int end, int target) {

        while (st != end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] < target) // valid
                end = mid;
            else
                st = mid + 1;
        }
        return st;
    }

// returns the index of targer
// 00001111
// 1 if it is greater than or equals the target
// we try to get the index of the target (smallest element greater than or equal the target)
    int BS2(vector<int> &nums, int st, int end, int target) {

        //if all are invalid (start is invalid and end is invalid) ==> all are 0s --> does not exist
        while (st != end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] >= target) // valid
                end = mid;
            else
                st = mid + 1;
        }
        return st;
    }


    int search(vector<int> &nums, int target) {

        if (nums[0] <= nums[nums.size() - 1]) // sorted
        {
            int result = BS2(nums, 0, nums.size() - 1, target);
            if (nums[result] != target)
                return -1;
            else
                return result;
        }
        int indexPivot = BS1(nums, 0, nums.size() - 1, nums[0]);
        int startingIndex;
        int endingIndex;
        int first = nums[0];
        if (target >= first) {
            startingIndex = 0;
            endingIndex = indexPivot - 1;
        } else {
            startingIndex = indexPivot;
            endingIndex = nums.size() - 1;
        }
        int result = BS2(nums, startingIndex, endingIndex, target);
        if (nums[result] != target)
            return -1;
        else
            return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    cout << sol.search(nums, target) << endl;
    return 0;
}