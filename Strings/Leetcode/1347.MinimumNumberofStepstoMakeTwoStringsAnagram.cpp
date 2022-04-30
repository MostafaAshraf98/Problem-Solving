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
    int minSteps(string s, string t) {
        map<char,int> mp;
        for(char letter :s)
        {
            if(mp.find(letter)==mp.end()) // if this char does not exist before
                mp[letter]=1;
            else
                mp[letter]++;
        }
        int count=0;
        for(char letter: t)
        {
            if(mp.find(letter)==mp.end() || mp[letter]==0) // if this letter does not exist
                count++;
            else
                mp[letter]--;
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    string s= "bab";
    string t = "aba";
    Solution S;
    cout << S.minSteps(s,t) << endl;

    s="leetcode";
    t="practice";
    cout << S.minSteps(s,t) << endl;

    s="anagram";
    t="mangaar";
    cout << S.minSteps(s,t) << endl;

    return 0;
}