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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for (auto p : prerequisites)
        {
            int from = p[1];
            int to = p[0];
            graph[from].push_back(to);
            ++indegree[to];
        }

        queue<int> zeroDegree;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                zeroDegree.push(i);
            }
        }

        vector<int> result;
        while (!zeroDegree.empty())
        {
            int course = zeroDegree.front();
            zeroDegree.pop();
            result.push_back(course);
            for (int child : graph[course])
            {
                --indegree[child];
                if (indegree[child] == 0)
                {
                    zeroDegree.push(child);
                }
            }
        }

        if (result.size() != numCourses)
        {
            return {};
        }

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