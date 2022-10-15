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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mpS;
        unordered_map<char, int> mpT;
        for (int i = 0; i < s.size(); i++) {
            if (mpS.find(s[i]) == mpS.end())
                mpS[s[i]] = 1;
            else
                mpS[s[i]]++;
            if (mpT.find(t[i]) == mpT.end())
                mpT[t[i]] = 1;
            else
                mpT[t[i]]++;
        }
        for (auto it = mpS.begin(); it != mpS.end(); it++) {
            char letter = it->first;
            int occ = it->second;
            if (mpT[letter] != occ)
                return false;
        }
        return true;
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