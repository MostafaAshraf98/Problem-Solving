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


    bool dfs(vector<bool> &memo, const vector<set<int>> &adjacencyList, vector<bool> visited, int currentNode,
             const int &destination) {
        set<int> neighbors = adjacencyList[currentNode];

        if (neighbors.size() == 0 && currentNode != destination)
            return false;

        if (visited[currentNode])
            return false;

        if (memo[currentNode])
            return memo[currentNode];

        visited[currentNode] = true;
        for (int neighbor: neighbors) {
            int ans = dfs(memo, adjacencyList, visited, neighbor, destination);
            if (!ans)
                return false;
        }
        return memo[currentNode] = true;
    }

    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
        vector<set<int>> adjacencyList(n);

        for (auto edge:edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].insert(to);
        }
        vector<bool> memo(n, false);
        vector<bool> visisted(n, false);
        return dfs(memo, adjacencyList, visisted, source, destination);
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