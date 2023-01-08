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

// What are the properties of minimum spanning tree
// 1- Minimum number of edges to connect all nodes (N-1) --> It is a tree, No Cycles
// 2- This tree has the minimum possible total edge weight in a "weighted undirected graph"

// Kruskal Algo
// 1) Ascending Sort all edges by their weight
// 2) Add edges in that order into the min spanning tree. Skip he edges that would produce cycles in the minimum spanning tree
// 3) Repeat step 2 until N-1 edges are added

class Solution {
public:
    bool cycleDetected(vector<vector<int>> &adjacencyList, vector<bool> &visited, int currentNode, int parent) {
        visited[currentNode] = true;
        vector<int> neighbors = adjacencyList[currentNode];
        for (int neighbor:neighbors) {
            if (neighbor == parent)
                continue;
            if (visited[neighbor])
                return true;
            bool ans = cycleDetected(adjacencyList, visited, neighbor, currentNode);
            if (ans)
                return true;
        }
        return false;
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        int N = points.size();
        if (N == 0 || N == 1)
            return 0;
        multimap<int, pair<int, int>> mp;
        // ascending sort all edges by their weight
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                mp.insert({dist, make_pair(i, j)});
            }
        }

        // loop over all edges and keep adding until N-1 edges are added and no cycles are formed
        int countEdge = 0;
        vector<vector<int>> adjacencyList(N);
        int answer = 0;
        for (auto it: mp) {
            if (countEdge == N - 1)
                break;
            int distance = it.first;
            pair<int, int> edge = it.second;
            int from = edge.first;
            int to = edge.second;
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
            vector<bool> visited(N, false);
            if (!cycleDetected(adjacencyList, visited, from, -1)) {
                countEdge++;
                answer += distance;
            } else {
                adjacencyList[from].pop_back();
                adjacencyList[to].pop_back();
            }
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