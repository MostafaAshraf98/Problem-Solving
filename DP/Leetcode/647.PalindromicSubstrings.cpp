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

    bool checkPalindrom(string s) {
        if (s.size() == 0)
            return false;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }

    int solve(string &s, vector<vector<int>> &memo, int start, int end) {
        if (end == s.size())
            return 0;

        if(memo[start][end]!=-1)
            return 0;

        int count = 0;
        if (checkPalindrom(s.substr(start, end - start + 1)))
            count++;
        // move start and end
        count += solve(s,memo, start + 1, end + 1);

        //move end only
        count += solve(s,memo, start, end + 1);

        return memo[start][end]= count;
    }

    int countSubstrings(string s) {
        vector<vector<int>> memo(s.size()+1, vector<int>(s.size()+1, -1));
        return solve(s,memo, 0, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    string s = "aaa";
    Solution sol;
    cout << sol.countSubstrings(s) << endl;
    return 0;
}