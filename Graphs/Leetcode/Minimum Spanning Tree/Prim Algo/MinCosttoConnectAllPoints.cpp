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


// Prim Algo:
// 1) Start with the first Node as the only Node in Visisted array
// 2) Put all the edges from the first Node into priority Queue Sorted by the edge cost
// 3) For every edge in the queue if the second node is not visisted,  mark it as visited, increase the cost by the edge value and put all the edges coming out of this Node
// into the queue condition that this edge it not linking it to a visited node


class Edge {
public:
    int point1;
    int point2;
    int cost;

    Edge(int point1, int point2, int cost) : point1(point1), point2(point2), cost(cost) {};
};

bool operator<(const Edge &edge1, const Edge &edge2) {
    return edge1.cost > edge2.cost;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        if (points.size() == 0)
            return 0;
        int result = 0;
        priority_queue<Edge> pq;
        vector<int> visited(points.size(), false);
        visited[0] = true;
        int x1 = points[0][0];
        int y1 = points[0][1];
        for (int j = 1; j < points.size(); j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int dist = abs(x1 - x2) + abs(y1 - y2);
            Edge edge(0, j, dist);
            pq.push(edge);
        }
        int count = points.size() - 1;
        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            int point1 = edge.point1;
            int point2 = edge.point2;
            int dist = edge.cost;
            if (!visited[point2]) {
                visited[point2] = true;
                result += dist;
                int x1 = points[point2][0];
                int y1 = points[point2][1];
                for (int j = 0; j < points.size(); j++) {
                    if (!visited[j]) {
                        int x2 = points[j][0];
                        int y2 = points[j][1];
                        int dist = abs(x1 - x2) + abs(y1 - y2);
                        Edge edge(point2, j, dist);
                        pq.push(edge);
                    }
                }
                count--;
            }
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