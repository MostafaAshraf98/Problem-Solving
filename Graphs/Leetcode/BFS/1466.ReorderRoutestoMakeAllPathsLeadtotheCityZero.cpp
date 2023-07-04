#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        int result = 0;
        vector<vector<int>> adjacencyList(n);
        vector<bool> visited(n, false);
        vector<vector<int>> initialConnections(n);
        for (auto connection: connections) {
            int from = connection[0];
            int to = connection[1];
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
            initialConnections[from].push_back(to);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            visited[from] = true;
            vector<int> neighbors = adjacencyList[from];
            for (int neighbor: neighbors) {
                if(visited[neighbor])
                    continue;

                vector<int> initialConnection = initialConnections[from];
                bool found = false;
                for(int con: initialConnection)
                {
                    if(con == neighbor)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    result += 1;
                q.push(neighbor);
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}