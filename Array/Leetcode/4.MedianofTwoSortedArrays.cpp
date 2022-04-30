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

//class Solution {
//public:
//    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//        bool isEven = false;
//        int m = nums1.size();
//        int n = nums2.size();
//        if ((m + n) % 2 == 0)
//            isEven = true;
//        vector<int> sorted;
//        int ptr1 = 0;
//        int ptr2 = 0;
//        while (ptr1 != m || ptr2 != n) {
//            if (ptr1 == m) {
//                sorted.push_back(nums2[ptr2]);
//                ptr2++;
//                continue;
//            }
//            if (ptr2 == n) {
//                sorted.push_back(nums1[ptr1]);
//                ptr1++;
//                continue;
//            }
//            if (nums1[ptr1] < nums2[ptr2]) {
//                sorted.push_back(nums1[ptr1]);
//                ptr1++;
//            } else if (nums1[ptr1] > nums2[ptr2]) {
//                sorted.push_back(nums2[ptr2]);
//                ptr2++;
//            } else {
//                sorted.push_back(nums1[ptr1]);
//                sorted.push_back(nums2[ptr2]);
//                ptr1++;
//                ptr2++;
//            }
//        }
//        if (!isEven)
//            return sorted[(m + n) / 2];
//        else
//            return (sorted[(m + n) / 2 - 1] + sorted[(m + n) / 2]) / 2.0;
//    }
//};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // The 1st array should be the smaller one and the second the larger one because of the following logic of balancing
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0; // the start of the window of array nums1
        int h = m; // the ned of the window of array nums1
        while (l <= h) {
            int ma = (l + h) / 2; // the new median of the window of array nums1
            //Note: (m+n)/2 is the total number of steps to get to the median
            int mb = (m + n) / 2 - ma; // the new median of the array b
            int L1 = ma != 0 ? nums1[ma - 1] : INT_MIN;
            int L2 = mb != 0 ? nums2[mb - 1] : INT_MIN;
            int R1 = ma != 0 ? nums1[ma] : INT_MIN;
            int R2 = mb != 0 ? nums2[mb] : INT_MIN;

            if (L2 <= R1 && L1 <= R2) {
                if ((m + n) % 2 == 1) // if it is odd then it is the middle
                    return min(R1, R2);
                else
                    return (max(L1, L2) + min(R1, R2)) / 2;
            } else if (R1 < L2) // if the right of nums1 less than the left of nums2 then remove the larger element
                l = ma + 1;
            else if (R2 < L1)
                h = ma - 1;
        }
        return INT_MIN;
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