#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)
#define sfs(s) scanf("%s", s)

#define pf(n) printf("%d", n)
#define pff(n, m) printf("%d %d", n, m)
#define pfl(n) printf("%I64d", n)
#define pffl(n, m) printf("%I64d %I64d", n, m)
#define pfs(s) printf("%s", s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int)10e4;

// Accepted
// MST
// Kruskal and Prim (MST)
class Edge
{
public:
    int point1;
    int point2;
    int cost;
    int index;
    Edge(int point1, int point2, int cost, int index) : point1(point1), point2(point2), cost(cost), index(index) {}
};

bool operator<(const Edge &edge1, const Edge &edge2)
{
    return edge1.cost > edge2.cost;
}

class UnionFind
{
private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    UnionFind(int size) : root(size), rank(size), count(size)
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    int getCount()
    {
        return count;
    }
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    int n;
    vector<Edge> newEdges;

    int kruskal(priority_queue<Edge> pq, int unUsed, int force)
    {
        int result = 0;
        int count = n - 1;
        UnionFind uf(n);

        if (force != -1)
        {
            Edge edge = newEdges[force];
            uf.unionSet(edge.point1, edge.point2);
            count--;
            result += edge.cost;
        }

        while (!pq.empty() && count != 0)
        {
            Edge edge = pq.top();
            pq.pop();

            if (edge.index == unUsed || edge.index == force)
                continue;

            if (!uf.isConnected(edge.point1, edge.point2))
            {
                count--;
                result += edge.cost;
                uf.unionSet(edge.point1, edge.point2);
            }
        }
        return result;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        priority_queue<Edge> pq;
        this->n = n;
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            Edge newEdge(edge[0], edge[1], edge[2], i);
            newEdges.push_back(newEdge);
            pq.push(newEdge);
        }

        int minCost = kruskal(pq, -1, -1);
        vector<int> criticalEdge;
        vector<int> pseudoEdge;

        for (int i = 0; i < edges.size(); i++)
        {
            vector<bool> temp(edges.size(), false);
            int ignoreCost = kruskal(pq, i, -1);

            if (ignoreCost == minCost)
            {
                int forceWeight = kruskal(pq, -1, i);
                if (forceWeight == minCost)
                    pseudoEdge.push_back(i);
            }
            else
                criticalEdge.push_back(i);
        }

        vector<vector<int>> result;
        result.push_back(criticalEdge);
        result.push_back(pseudoEdge);
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}