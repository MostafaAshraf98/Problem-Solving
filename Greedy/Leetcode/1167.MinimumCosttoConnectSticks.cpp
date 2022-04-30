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

//https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int connectSticks(vector<int> &sticks) {
        if (sticks.size() == 1)
            return 0;
        else if (sticks.size() == 2)
            return sticks[0] + sticks[1];
        multiset<int> s;
        for (int i = 0; i < sticks.size(); i++)
            s.insert(sticks[i]);
        int count = 0;
        while (s.size() != 1) {
            auto it1 = s.begin();
            auto it2 = s.begin();
            it2++;
            int sum = *it1 + *it2;
            count += sum;
            s.erase(it1, ++it2);
            s.insert(sum);
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
    vector<int> sticks = {2,4,3};
    Solution* sol = new Solution();
    cout << sol->connectSticks(sticks) << endl;
    return 0;
}