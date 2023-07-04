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

bool
pathExists(const vector<vector<int>> &adjacencyList, unordered_map<int, bool> &visited, int currentNode,
           const int &targetNode) {
    if (visited.find(currentNode) != visited.end())
        return false;

    if (currentNode == targetNode)
        return true;

    vector<int> neighbors = adjacencyList[currentNode];
    bool result = false;
    for (int neighbor: neighbors) {
        result = pathExists(adjacencyList, visited, neighbor, targetNode);
        if (result)
            break;
    }
    return result;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacencyList(n);
        for(int i=0;i<edges.size();i++)
        {
            int to = edges[i][0];
            int from = edges[i][1];
            adjacencyList[to].push_back(from);
            adjacencyList[from].push_back(to);
        }
        unordered_map<int, bool> visited;
        return pathExists(adjacencyList,visited,source,destination);
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