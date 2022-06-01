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

//https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:

    // The array is zeros then ones because we are trying to get

    bool valid(int k, vector<int> piles, int h) {
        int j = 0; // iterator over the piles
        while (h > 0) {
            h -= ceil((double) piles[j] / (double) k);
            j++;
            if (j == piles.size() && h >= 0)
                return true;
        }
        return false;
    }

    int BS(vector<int> &piles, int &h) {
        long long start = 0;
        long long end = 1e9 + 1;
        while (start < end) {
            long long mid = start + (end - start) / 2;
            if (valid(mid, piles, h))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        if (piles.size() == 0)
            return 0;
        if (piles.size() == 1)
            return ceil((double) piles[0] / (double) h);
        return BS(piles, h);
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