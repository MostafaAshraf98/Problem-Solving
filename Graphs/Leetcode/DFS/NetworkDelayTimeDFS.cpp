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

    void
    DFS(const vector<vector<pair<int, int>>> &adjacencyList, vector<int> &cost, int currentCost, int currentNode) {

        if (cost[currentNode] <= currentCost)
            return;

        cost[currentNode] = currentCost;
        vector<pair<int, int>> neighbors = adjacencyList[currentNode];

        for (pair<int, int> neighbor: neighbors)
            DFS(adjacencyList, cost, currentCost + neighbor.second, neighbor.first);
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        vector<int> cost(n, INT_MAX);
        for (auto time:times) {
            int from = time[0] - 1;
            int to = time[1] - 1;
            int weight = time[2];
            adjacencyList[from].push_back(make_pair(to, weight));
        }
        for (int i = 0; i < adjacencyList.size(); i++) {
            sort(adjacencyList[i].begin(), adjacencyList[i].end());
        }
        int result = INT_MIN;
        DFS(adjacencyList, cost, 0, k - 1);
        for (int c: cost) {
            if (c == INT_MAX)
                return -1;
            result = max(result, c);
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