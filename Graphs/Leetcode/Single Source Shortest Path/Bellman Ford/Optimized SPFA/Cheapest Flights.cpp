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

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst)
    {
        if (src == dst)
        {
            return 0;
        }
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> flight : flights)
        {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            adj[from].push_back({cost, to});
        }

        vector<int> current(n, INT_MAX);
        queue<int> q;
        vector<bool> visited(n, 0);

        current[src] = 0;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            visited[currentNode] = false;

            int currentCost = current[currentNode];
            for (pair<int, int> edge : adj[currentNode])
            {
                int weight = edge.first;
                int to = edge.second;
                int newCost = currentCost + weight;
                if (newCost < current[to])
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