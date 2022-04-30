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
    string customSortString(string order, string s) {
        vector<char> letterInOrder;
        unordered_map<char, int> occurencesInS;
        for (int i = 0; i < order.size(); i++) {
            letterInOrder.push_back(order[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            if (occurencesInS.find(s[i]) == occurencesInS.end()) // it does not exist
                occurencesInS[s[i]] = 1;
            else
                occurencesInS[s[i]]++;
        }
        string result = "";
        for (int j = 0; j < letterInOrder.size(); j++) {
            auto it2 = occurencesInS.find(letterInOrder[j]);
            if (it2 != occurencesInS.end()) {
                for (int i = 0; i < it2->second; i++) {
                    result += it2->first;
                }
                occurencesInS.erase(it2);
            }
        }
        for (auto it = occurencesInS.begin(); it != occurencesInS.end(); it++) {
            for (int i = 0; i < it->second; i++)
                result += it->first;
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