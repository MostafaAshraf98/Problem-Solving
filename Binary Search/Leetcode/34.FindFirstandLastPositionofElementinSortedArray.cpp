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

// binary search
//00000011111
// 1 if it is greater than the target and 0 if it is less than the target

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int st = 0;
        int end = nums.size() + 1;
        vector<int> answer(2, -1);
        if (nums.size() == 0 || nums[nums.size() - 1] < target || nums[0] > target)
            return answer;
        // if we reached this line then it means that there is at least one element less than or equal to target
        // so there is at least one 1
        if (nums.size() == 1) {
            if (nums[0] == target) {
                answer[0] = 0;
                answer[1] = 0;

            }
            return answer;
        }
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] >= target) // valid
                end = mid;
            else
                st = mid + 1;
        }
        // now we found the first element greater than or equal the target
        if (nums[st] == target) {
            answer[0] = st;
        } else
            return;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] > target) // valid
                end = mid;
            else
                st = mid + 1;
        }
        // st is the index of the first element greater than the
        if (st - 1 >= 0)
            answer[1]= st-1;
        return answer;

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