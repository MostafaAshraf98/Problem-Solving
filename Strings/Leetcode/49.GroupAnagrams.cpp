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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<multiset<char>, vector<string>> mp;
        for (auto str : strs) {
            multiset<char> s;
            for (auto letter: str) {
                s.insert(letter);
            }
            auto it = mp.find(s);
            if (it != mp.end()) // it exists before
            {
                it->second.push_back(str);
            } else {
                vector<string> v;
                v.push_back(str);
                mp[s] = v;
            }
        }
        vector<vector<string>> result;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<string> v = it->second;
            result.push_back(v);
        }
        return result;

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