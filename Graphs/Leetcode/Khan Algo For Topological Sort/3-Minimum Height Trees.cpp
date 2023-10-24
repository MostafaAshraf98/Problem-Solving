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
    int solve(const vector<vector<int>> &graph, vector<vector<int>> &memo, int currentNode, int parent)
    {
        if (parent != -1 && graph[currentNode].size() == 1)
            return 1;

        if (parent != -1 && memo[currentNode][parent] != -1)
            return memo[currentNode][parent];

        int max = -1;
        for (int child : graph[currentNode])
        {
            if (child == parent)
                continue;
            int path = 1 + solve(graph, memo, child, currentNode);
            if (path > max)
                max = path;
        }
        if (parent != -1)
            return memo[currentNode][parent] = max;
        return max;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        vector<vector<int>> graph(n);
        for (vector<int> edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(n, -1));
        int minVal = INT_MAX;
        vector<int> min;
        for (int i = 0; i < n; i++)
        {
            int path = solve(graph, memo, i, -1);
            if (path == minVal)
            {
                min.push_back(i);
            }
            else if (path < minVal)
            {
                vector<int> newMin;
                newMin.push_back(i);
                min = newMin;
                minVal = path;
            }
        }
        return min;
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