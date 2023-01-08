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

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        if(source==destination)
            return true;

        vector<vector<int>> adjacencyList(n);
        for (auto edge:edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        vector<int> seen(n, false);
        queue<int> q;
        q.push(source);
        seen[source]=true;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for (int neighbor:adjacencyList[currentNode]) {
                if(neighbor== destination)
                    return true;
                if (!seen[neighbor])
                {
                    seen[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return false;
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