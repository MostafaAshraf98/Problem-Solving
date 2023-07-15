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
    vector<vector<int>> graph;
    vector<int> memo;
    vector<bool>visited;
    int n;

    int dfs(int currentNode)
    {
        vector<int> neighbors = graph[currentNode];

        if (neighbors.size() == 0)
            return memo[currentNode] = 1;

        if (memo[currentNode] != -1)
            return memo[currentNode];

        if(visited[currentNode])
            return memo[currentNode] = 0; 

        visited[currentNode] = true;

        int isSafeNode = 1;
        for (int neighbor : neighbors)
        {
            int result = dfs(neighbor);
            if (result == 0)
                isSafeNode = 0;
        }
        return memo[currentNode] = isSafeNode;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        n = graph.size();
        this->graph = graph;
        memo = vector<int>(n, -1);
        visited= vector<bool>(n,false);
        vector<int> result;

        for(int i=0;i<graph.size();i++)
            dfs(i);

        for (int i = 0; i < graph.size(); i++)
            if (memo[i] == 1)
                result.push_back(i);
                
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