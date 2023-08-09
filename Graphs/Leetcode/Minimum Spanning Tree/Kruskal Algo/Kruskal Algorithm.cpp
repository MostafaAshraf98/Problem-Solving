#include <bits/stdc++.h>
using namespace std;

// What are the properties of minimum spanning tree
// 1- Minimum number of edges to connect all nodes (N-1) --> It is a tree, No Cycles
// 2- This tree has the minimum possible total edge weight in a "weighted undirected graph"

// Kruskal Algo
// 1) Ascending Sort all edges by their weight
// 2) Add edges in that order into the min spanning tree. Skip he edges that would produce cycles in the minimum spanning tree
// 3) Repeat step 2 until N-1 edges are added

class Edge
{
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};

// Overload the < operator.
bool operator<(const Edge &edge1, const Edge &edge2)
{
    return edge1.cost > edge2.cost;
}

class UnionFind
{
public:
    UnionFind(int sz) : root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == root[x])
        {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution
{
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int sz = points.size();
        if (sz == 0)
        {
            return 0;
        }
        priority_queue<Edge> pq;

        for (int i = 0; i < sz; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < sz; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                Edge edge(i, j, dist);
                pq.push(edge);
            }
        }

        UnionFind uf(sz);
        int result = 0;
        int count = sz - 1;

        while (!pq.empty() && count > 0)
        {
            Edge edge = pq.top();
            pq.pop();

            if (!uf.connected(edge.point1, edge.point2))
            {
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};