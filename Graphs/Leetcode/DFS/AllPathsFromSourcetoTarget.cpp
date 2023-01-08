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
    void dfs(const vector<vector<int>> &graph, vector<int> &visited, int currentNode, const int &targetNode,
             vector<int> currentPath, vector<vector<int>> &result) {
        if (visited[currentNode] != -1)
            return;

        if (currentNode == targetNode) {
            currentPath.push_back(currentNode);
            result.push_back(currentPath);
            return;
        }

        vector<int> neighbors = graph[currentNode];
        currentPath.push_back(currentNode);
        visited[currentNode] = 1;
        for (int neighbor: neighbors) {
            dfs(graph, visited, neighbor, targetNode, currentPath, result);
        }
        visited[currentNode] = -1;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<vector<int>> result;
        if (graph.size() == 0)
            return result;
        vector<int> currentPath;
        dfs(graph, visited, 0, n - 1,currentPath,result);
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