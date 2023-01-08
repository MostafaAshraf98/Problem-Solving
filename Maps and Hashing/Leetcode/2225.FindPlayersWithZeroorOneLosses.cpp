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
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        vector<vector<int>> answer(2, vector<int>());
        map<int, int> losers;
        for (auto match:matches) {
            int winner = match[0];
            int loser = match[1];
            if (losers.find(loser) == losers.end()) // first time to lose
                losers[loser] = 1;
            else
                losers[loser] += 1;
            if (losers.find(winner) == losers.end()) // this player is not in the map
                losers[winner] = 0;

        }
        for (auto it = losers.begin(); it != losers.end(); it++) {
            int player = it->first;
            int numLoses = it->second;
            if (numLoses == 0)
                answer[0].push_back(player);
            else if (numLoses == 1)
                answer[1].push_back(player);
        }
        return answer;

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