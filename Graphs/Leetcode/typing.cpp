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
        if (root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }

    int unionSet(int x, int y)
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
    int isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

void bfs(vector<vector<int>> adj, int n)
{
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        vector<int> neighbors = adj[currentNode];
        for (int neighbor : neighbors)
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, const int &n, int currentNode)
{
    for (int neighbor : adj[currentNode])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            dfs(adj, visited, n, currentNode);
        }
    }
}

int kruskal(vector<vector<int>> edges, int n)
{
    priority_queue<Edge> pq;
    for (vector<int> edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        Edge newEdge(from, to, cost);
        pq.push(newEdge);
    }
    UnionFind uf(n);
    int result = 0;
    int count = n - 1;
    while (!pq.empty() && count != 0)
    {
        Edge edge = pq.top();
        pq.pop();
        if (!uf.isConnected(edge.point1, edge.point2))
        {
            result += edge.cost;
            count--;
            uf.unionSet(edge.point1, edge.point2);
        }
    }
    return result;
}

int prim(vector<vector<pair<int, int>>> adj, int n)
{
    priority_queue<Edge> pq;
    vector<bool> visited(n, false);

    visited[0] = true;
    for (pair<int, int> neighbor : adj[0])
    {
        Edge edge(0, neighbor.second, neighbor.first);
        pq.push(edge);
    }

    int result = 0;
    int count = n - 1;
    while (!pq.empty() && count != 0)
    {
        Edge edge = pq.top();
        pq.pop();
        int point1 = edge.point1;
        int point2 = edge.point2;
        int cost = edge.cost;
        if (!visited[point2])
        {
            visited[point2] = true;
            result += cost;
            count--;
            for (pair<int, int> neighbor : adj[point2])
            {

                if (!visited[neighbor.second])
                {
                    visited[neighbor.second] = true;
                    Edge edge(point2, neighbor.second, neighbor.first);
                    pq.push(edge);
                }
            }
        }
    }
    return result;
}

int djikstra(vector<vector<pair<int, int>>> adj, int n, int src, int dst)
{
    if (src == dst)
        return 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> cost(n, INT_MAX);

    cost[src] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();
        if (cost[currentNode] < currentCost)
            continue;
        for (pair<int, int> edge : adj[currentNode])
        {
            int neighbor = edge.second;
            int weight = edge.second;
            int newCost = currentCost + weight;
            if (newCost < cost[neighbor])
            {
                pq.push({newCost, neighbor});
                cost[neighbor] = newCost;
            }
        }
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
}

int bellmanFord_standard(vector<vector<int>> edges, int n, int k, int src, int dst)
{
    if (src == dst)
        return 0;

    vector<int> current(n, INT_MAX);
    vector<int> previous(n, INT_MAX);

    previous[src] = 0;
    for (int i = 0; i < k; i++)
    {
        current[src] = true;
        for (vector<int> edge : edges)
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

    vector<int> current(n, INT_MAX);
    vector<bool> visited(n, false);
    queue<int> q;

    current[src] = 0;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        visited[currentNode] = false;
        for (pair<int, int> edge : adj[currentNode])
        {
            int to = edge.second;
            int weight = edge.first;
            int newCost = current[currentNode] + weight;
            if (current[to] > newCost)
            {
                current[to] = newCost;
                if (!visited[to])
                {
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
    }
    return current[dst] == INT_MAX ? -1 : current[dst];
}

vector<int> khan(vector<vector<int>> adj, int n)
{
    vector<int> inDegrees(n, 0);
    vector<int> result;
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
        zeroDegrees.pop();
        result.push_back(currentNode);
        for (int neighbor : adj[currentNode])
        {
            inDegrees[neighbor]--;
            if (inDegrees[neighbor] == 0)
                zeroDegrees.push(neighbor);
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