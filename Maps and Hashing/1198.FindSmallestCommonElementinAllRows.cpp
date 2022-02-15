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

//https://leetcode.com/problems/find-smallest-common-element-in-all-rows/submissions/

class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        vector<int> initialVec = mat[0];
        vector<map<int, int>> vec;
        for (int i = 1; i < mat.size(); i++) {
            map<int, int> mp;
            for (int j = 0; j < mat[i].size(); j++)
                mp[mat[i][j]] = 1;
            vec.push_back(mp);
        }
        for (int i = 0; i < initialVec.size(); i++) // loop over the elements in initialVec
        {
            bool foundInAll = true;
            for (auto mp: vec) {
                if (mp.find(initialVec[i]) == mp.end()) {
                    foundInAll = false;
                    break;
                }
            }
            if (foundInAll)
                return initialVec[i];
        }
        return -1;
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