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

//https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        map<string, int> mp;
        for (int i = 0; i < cpdomains.size(); i++) {
            size_t pos = 0;
            pos = cpdomains[i].find(" ");
            string s = cpdomains[i].substr(0, pos);
            int count = stoi(s);
            cpdomains[i].erase(0, pos + 1);
            string currentDomain = cpdomains[i];
            //---------------------
            if (auto it = mp.find(cpdomains[i]) == mp.end()) //it does not exist
                mp[cpdomains[i]] = count;
            else
                mp[cpdomains[i]] += count;
            //---------------------------------
            pos = 0;
            int last = 0;
            while ((pos = currentDomain.find(".")) != string::npos) {
                string word = cpdomains[i].substr(last + pos + 1, cpdomains[i].size());
                if (auto it = mp.find(word) == mp.end()) //it does not exist
                    mp[word] = count;
                else
                    mp[word] += count;
                last = last + pos + 1;
                currentDomain.erase(0, pos + 1);
            }
        }
        vector<string> result;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            string s = "";
            s += to_string(it->second);
            s += " ";
            s += it->first;
            result.push_back(s);
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
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution sol;
    vector<string> result = sol.subdomainVisits(cpdomains);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}