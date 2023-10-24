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
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (vector<int> road : roads)
        {
            int a = road[0];
            int b = road[1];
            int cost = road[2];
            graph[a].push_back({cost, b});
            graph[b].push_back({cost, a});
        }
        int answer = INT_MAX;
        queue<int> q;
        vector<bool> visited(n + 1, false);

        visited[1] = true;
        q.push(1);

        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            for (pair<int, int> edge : graph[currentNode])
            {
                int cost = edge.first;
                int neighbor = edge.second;
                answer = min(answer, cost);
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return answer;
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