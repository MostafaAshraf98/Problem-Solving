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

    int solve(vector<string> &words, map<string, int> &memo, string currentStr) {
        if (find(words.begin(), words.end(), currentStr) == words.end()) // did not find the word
            return 0;

        if (memo.find(currentStr) != memo.end())
            return memo[currentStr];

        int currentMax = 0;
        for (int i = 0; i < currentStr.size(); i++) {
            //try to remove every letter
            string temp = currentStr;
            currentStr.erase(i, 1);
            int val = 1 + solve(words, memo, currentStr);
            if (val > currentMax)
                currentMax = val;
            currentStr = temp;
        }
        return memo[currentStr] = currentMax;
    }

    int longestStrChain(vector<string> &words) {
        map<string, int> memo;
        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            int val = solve(words, memo, words[i]);
            if (val > max)
                max = val;
        }
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