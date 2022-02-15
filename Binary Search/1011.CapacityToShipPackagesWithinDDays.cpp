
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

//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//Binary Search
//the array is zeros then ones because we are trying to get the minimum

class Solution {
public:

    bool valid(int n, vector<int> &weights, int days) {
        int currentWeight = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currentWeight + weights[i] > n) {
                days--;
                if (days == 0) // all days are gone and there is still weights to carry
                    return false;
                if (weights[i] > n) // if this single weight is greater than the ships' capacity
                    return false;
                currentWeight = weights[i];
            } else
            {
                currentWeight+=weights[i];
            }
        }
        return true;

    }

    int shipWithinDays(vector<int> &weights, int days) {
        long long st = 0;
        long long end = 500 * 5 * 10e4 + 2;
        while (st < end) {
            long long mid = st + (end - st ) / 2;
            if (valid(mid, weights, days))
                end = mid;
            else
                st = mid + 1;
        }
        return st;
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