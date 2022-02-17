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

//https://leetcode.com/problems/flip-string-to-monotone-increasing/
class Solution {
public:

    int solve(string &s, vector<vector<int>> &memo, int index, int prev) {
        if (index == s.size())
            return 0;
        if (prev != -1 && memo[index][prev] != -1)
            return memo[index][prev];

        //flip if possible (possible only if mesh zay eli abli fa ha2lebo 3alashan a5alih zay eli abli)
        int flip = INT_MAX;
        if (prev == -1 || prev != s[index] - '0') {
            if (s[index] == '0')
                flip = 1 + solve(s, memo, index + 1, 1);
            else
                flip = 1 + solve(s, memo, index + 1, 0);
        }

        //no flip is possible law zay eli abli aw law eli abli kan 0 (fana hab2a 0 zayo aw hab2a 1 (still increasing))
        int noFlip = INT_MAX;
        if (prev == -1 || prev == 0 || prev == s[index] - '0')
            noFlip = solve(s, memo, index + 1, s[index] - '0');

        if (prev != -1)
            return memo[index][prev] = min(flip, noFlip);
        else
            return min(flip, noFlip);
    }

    int minFlipsMonoIncr(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(2, -1));
        return solve(s, memo, 0, -1);

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