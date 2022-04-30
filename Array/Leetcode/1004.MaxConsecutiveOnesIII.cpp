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
    int longestOnes(vector<int> &nums, int k) {
        int ptr1 = 0;
        int ptr2 = 0;
        int max = 0;
        int currentCount = 0;
        int remainingFlips = k;
        while (ptr2 != nums.size()) {
            if (nums[ptr2] == 1) {
                ptr2++;
                currentCount++;
            } else {
                if (remainingFlips != 0) {
                    ptr2++;
                    currentCount++;
                    remainingFlips--;
                } else // There are no remaining flips
                {
                    if (currentCount > max)
                        max = currentCount;
                    //Move ptr1 until it passes a 0
                    while (true) {
                        if (nums[ptr1 == 1]) {
                            ptr1++;
                            currentCount--;
                        } else {
                            ptr1++;
                            break;
                        }
                    }
                    ptr2++;
                }
            }
        }
        if (currentCount > max)
            max = currentCount;
        return max;

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