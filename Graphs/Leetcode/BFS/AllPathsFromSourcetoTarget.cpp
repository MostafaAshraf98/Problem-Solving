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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        queue<vector<int>> q;
        vector<vector<int>> answer;

        vector<int> initialPath;
        initialPath.push_back(0);
        q.push(initialPath);

        while (!q.empty()) {
            vector<int> currentPath = q.front();
            q.pop();
            int currentNode = currentPath[currentPath.size() - 1];
            vector<int> neighbors = graph[currentNode];
            for(int neighbor:neighbors)
            {
                currentPath.push_back(neighbor);
                if(neighbor== graph.size())
                    answer.push_back(currentPath);
                else
                    q.push(currentPath);
                q.pop();
            }
        }
        return answer;
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