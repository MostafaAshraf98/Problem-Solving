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

bool hasCycle = false;

void dfs(vector<vector<int>> &list, vector<int> &visited, vector<int> &ans, int src) {
    visited[src] = 2; // Mark it as running
    for (auto ch: list[src]) {
        if (visited[ch] == 2) {
            hasCycle = true;
            return;;
        }
        if (visited[ch] == 0)
            dfs(list, visited, ans, ch);
    }
    visited[src] = 1; // Mark it as visited
    ans.push_back(src+1);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    // undirected
    int n; // the number of sticks (Nodes)
    int m; // the number of edges (connected sticks)
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        hasCycle = false;
        vector<vector<int>> adjacencyList(n);
        vector<int> ans;
        vector<int> visited(n, 0);
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            adjacencyList[from-1].push_back(to-1);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(adjacencyList, visited, ans, i);
        }
        if (hasCycle) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        reverse(ans.begin(),ans.end());
        for (int x: ans)
            cout << x << endl;

    }
    return 0;
}