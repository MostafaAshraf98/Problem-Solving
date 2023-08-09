#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) {
            return 0;
        }

        vector<int> previous(n, INT_MAX);
        vector<int> current(n, INT_MAX);
        previous[src] = 0;
        //Here k is the number of stops/cities. The number of edges = k+1 since you can use 2 edges to go from src to dst and you will stop at 1 city.
        for (int i = 1; i <= k + 1; i++) {
            // always the source to source cost is 0
            current[src] = 0;
            
            //loop over all the edges
            for (vector<int>& flight : flights) {
                int previous_flight = flight[0]; // from
                int current_flight = flight[1]; // to
                int cost = flight[2]; // price

                // if the previous is INT_MAX then in this case mahma 7awelt enak tezawed 3aleih hayefdal INT_MAX fa malhash lazma eni a7awel
                if (previous[previous_flight] < INT_MAX) {
                    current[current_flight] = min(current[current_flight],
                                                  previous[previous_flight] + cost);
                }
            }
            previous.assign(current.begin(), current.end());
        }
        return current[dst] == INT_MAX ? -1 : current[dst];
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