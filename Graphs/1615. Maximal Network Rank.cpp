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
//Graphs

class Solution
{
public:
    bool isNeighbor(const vector<int> &neighbors, int target)
    {
        for (int neighbor : neighbors)
            if (neighbor == target)
                return true;
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> graph(n);
        for (vector<int> road : roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = graph[i].size() + graph[j].size();
                if (isNeighbor(graph[i], j))
                    count--;
                if (count > max)
                    max = count;
            }
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