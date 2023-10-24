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

//Accepted
//Directed graphs, BFS

class Solution
{
public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        vector<vector<int>> graph(bombs.size());
        for (int i = 0; i < bombs.size(); i++)
        {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for (int j = i + 1; j < bombs.size(); j++)
            {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];
                bool firstToSecond = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) <= r1;
                if (firstToSecond)
                    graph[i].push_back(j);
                bool secondToFirst = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) <= r2;
                if (secondToFirst)
                    graph[j].push_back(i);
            }
        }
        int max = -1;
        for (int i = 0; i < bombs.size(); i++)
        {
            vector<bool> visited(bombs.size(), false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int count = 1;
            while (!q.empty())
            {
                int currentNode = q.front();
                q.pop();
                vector<int> neighbors = graph[currentNode];
                for (int neighbor : neighbors)
                {
                    if (!visited[neighbor])
                    {
                        count++;
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            if (count > max)
                max = count;
        }
        return max;
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