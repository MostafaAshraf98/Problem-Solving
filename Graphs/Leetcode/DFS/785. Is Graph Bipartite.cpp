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
// Graphs

class Solution
{
public:
    unordered_map<int, bool> A;
    unordered_map<int, bool> B;
    vector<vector<int>> graph;
    vector<bool> visited;
    bool dfs(int currentNode, int parent)
    {
        char currentGroup;
        if (A.find(parent) == A.end())
        {
            currentGroup = 'A';
            A[currentNode] = true;
        }
        else
        {
            currentGroup = 'B';
            B[currentNode] = true;
        }
        for (int neighbor : graph[currentNode])
        {
            if (neighbor != parent)
            {
                if (currentGroup == 'A' && A.find(neighbor) != A.end())
                    return false;
                else if (currentGroup == 'B' && B.find(neighbor) != B.end())
                    return false;
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    bool answer = dfs(neighbor, currentNode);
                    if (!answer)
                        return answer;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        this->graph = graph;
        visited = vector<bool>(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                bool answer = dfs(i, -1);
                if (!answer)
                    return answer;
            }
        }

        return true;
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