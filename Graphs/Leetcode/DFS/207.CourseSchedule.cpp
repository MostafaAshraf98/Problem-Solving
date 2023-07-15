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
    vector<vector<int>> adjacencyList;
    vector<int> memo;

    int hasCycle(int currentNode, vector<bool> &visited)
    {
        vector<int> neighbors = adjacencyList[currentNode];
        if (neighbors.size() == 0)
            return false;

        if (memo[currentNode] != -1)
            return memo[currentNode];

        if (visited[currentNode])
            return memo[currentNode] = 1;

        visited[currentNode] = true;
        for (int neighbor : neighbors)
        {
            bool result = hasCycle(neighbor, visited);
            if (result == 1)
                return memo[currentNode] = 1;
        }
        return memo[currentNode] = 0;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses <= 1)
            return true;
        adjacencyList = vector<vector<int>>(numCourses);
        memo = vector<int>(numCourses, -1);

        for (vector<int> prerequesite : prerequisites)
            adjacencyList[prerequesite[0]].push_back(prerequesite[1]);

        for (int i = 0; i < numCourses; i++)
        {
            vector<bool> visited(numCourses, false);
            if (memo[i] == -1)
            {
                bool result = hasCycle(i, visited);
                if (result)
                    return false;
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