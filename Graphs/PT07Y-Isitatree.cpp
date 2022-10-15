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

// For a graph to be a tree, it must be:
// Acyclic
// number of edges = number of nodes -1
// Only 1 component

void dfs(vector<vector<int>> &adjacencyList, vector<int> &visited, vector<int> &ans,vector<int>&parent, bool &hasCycle, int src) {
    //Running
    visited[src] = 2;
    for (auto child: adjacencyList[src]) {
        if (visited[child] == 0) // not Visited
        {
            parent[child]=src;
            dfs(adjacencyList, visited, ans,parent, hasCycle, child);
        }
        else if (visited[child] == 1)
            continue;
        else if (visited[child] == 2 && parent[src]!= child) {
            hasCycle = true;
            return;
        }
    }
    visited[src] = 1;
    ans.push_back(src);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n; // number of nodes
    int m; // number of edges
    cin >> n >> m;
    if (m != n - 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<int>> adjacencyList(n+1);
    vector<int> parent(n+1);
    vector<int> visited(n+1, 0);
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }
    int count = 0;
    bool hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            if (count > 1) {
                cout << "NO" << endl;
                return 0;
            }
            dfs(adjacencyList, visited, ans,parent, hasCycle, 1);
        }
    }
    if (hasCycle) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}