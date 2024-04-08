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

class Edge
{
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost) : point1(point1), point2(point2), cost(cost) {}
};

bool operator<(const Edge &edge1, const Edge &edge2)
{
    return edge1.cost > edge2.cost;
}

// Used for disjoint sets and in kruskal algorithm
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
                rank[rootX]++;
                root[rootY] = rootX;
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
        return find(y) == find(x);
    }
};

void bfs(vector<vector<int>> &adj, int n)
{
    queue<int> q;
    vector<bool> visited(n);

    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (int neighbor : adj[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(const vector<vector<int>> &adj, const int &n, vector<bool> visited, int currentNode)
{
    for (int neighbor : adj[currentNode])
    {
        if (!visited[currentNode])
        {
            visited[currentNode] = true;
            dfs(adj, n, visited, neighbor);
        }
    }
}

// minimum spanning tree
int kruskal(const vector<vector<int>> edges, int n)
{
    priority_queue<Edge> pq;

    for (auto edge : edges)
    {
        Edge edge(edge[0], edge[1], edge[2]);
        pq.push(edge);
    }

    UnionFind uf(n);
    int count = n - 1;
    int result = 0;

    while (!pq.empty() && count > 0)
    {
        Edge currentEdge = pq.top();
        pq.pop();
        if (!uf.isConnected(currentEdge.point1, currentEdge.point2))
        {
            uf.unionSet(currentEdge.point1, currentEdge.point2);
            count--;
            result += currentEdge.cost;
        }
    }
    return result;
}

int prim(const vector<vector<pair<int, int>>> adj, int n)
{
    priority_queue<Edge> pq;
    vector<bool> visited(n);

    visited[0] = true;
    for (auto edge : adj[0])
    {
        Edge newEdge(0, edge.second, edge.first);
        pq.push(newEdge);
    }
    int result = 0;
    int count = n - 1;
    while (!pq.empty() && count > 0)
    {
        Edge currentEdge = pq.top();
        pq.pop();
        int point1 = currentEdge.point1;
        int point2 = currentEdge.point2;
        int cost = currentEdge.cost;
        if (!visited[point2])
        {
            visited[point2] = true;
            result += cost;
            count--;

            for (auto edge : adj[point2])
            {
                if (!visited[edge.second])
                {
                    Edge newEdge(point2, edge.second, edge.first);
                    pq.push(newEdge);
                }
            }
        }
    }
    return result;
}

int djikstra(const vector<vector<pair<int, int>>> adj, int n, int src, int dst)
{
    if (src == dst)
        return 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> cost(n, INT_MAX);

    cost[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        if (cost[currentNode] < currentWeight)
            continue;

        for (auto edge : adj[currentNode])
        {
            int neighbor = edge.second;
            int weight = edge.first;
            int newCost = currentWeight + weight;
            if (newCost < cost[neighbor])
            {
                cost[neighbor] = newCost;
                pq.push({newCost, neighbor});
            }
        }
    }

    return cost[dst] == INT_MAX ? -1 : cost[dst];
}

int bellmanFord_standard(vector<vector<int>> edges, int n, int src, int dst, int k)
{
    if (src == dst)
        return 0;

    vector<int> previous(n, INT_MAX);
    vector<int> current(n, INT_MAX);

    previous[src] = 0;
    for (int i = 0; i < k; i++)
    {
        current[src] = 0;
        for (auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            if (previous[from] != INT_MAX)
                current[to] = min(current[to], previous[from] + cost);
        }
        previous.assign(current.begin(), current.end());
    }
    return current[dst] == INT_MAX ? -1 : current[dst];
}

int bellmanFord_SPFA(vector<vector<pair<int, int>>> adj, int n, int src, int dst)
{
    if (src == dst)
        return 0;
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> current(n, INT_MAX);

    q.push(src);
    visited[src] = true;
    current[src] = 0;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        visited[currentNode] = false;
        for (auto edge : adj[currentNode])
        {
            int neighbor = edge.second;
            int weight = edge.first;
            int newCost = weight + current[currentNode];
            if (newCost < current[neighbor])
            {
                current[neighbor] = newCost;
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    return current[dst] == INT_MAX ? -1 : current[dst];
}

vector<int> khan(vector<vector<int>> adj, int n)
{
    vector<int> result;
    vector<int> inDegrees(n, 0);
    queue<int> zeroDegrees;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            inDegrees[neighbor]++;

    for (int i = 0; i < n; i++)
        if (inDegrees[i] == 0)
            zeroDegrees.push(i);

    while (!zeroDegrees.empty())
    {
        int currentNode = zeroDegrees.front();
        result.push_back(currentNode);
        zeroDegrees.pop();
        for (int neighbor : adj[currentNode])
        {
            inDegrees[neighbor]--;
            if (inDegrees[neighbor] == 0)
                q.push(neighbor);
        }
    }
    if (result.size() != n)
        return {};
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}