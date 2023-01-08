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
    int count = 0;
    unordered_map<string, multiset<string>> adjacencyList;
    vector<string> result;
    unordered_map<string, vector<bool>> visitedNeighbors;

    bool dfs(string currentNode, vector<string> currentPath) {
        currentPath.push_back(currentNode);
        multiset<string> neighbors = adjacencyList[currentNode];

        if (currentPath.size() == count) {
            result = currentPath;
            return true;
        }
        int i = 0;
        for (string neighbor:neighbors) {
            if (!visitedNeighbors[currentNode][i]) {
                visitedNeighbors[currentNode][i] = true;
                bool ans = dfs(neighbor, currentPath);
                if (ans)
                    return true;
                visitedNeighbors[currentNode][i] = false;
            }
            i++;
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto ticket: tickets) {
            string from = ticket[0];
            string to = ticket[1];
            if (adjacencyList.find(from) != adjacencyList.end())
                adjacencyList[from].insert(to);
            else {
                multiset<string> v;
                v.insert(to);
                adjacencyList[from] = v;
            }
        }
        for (auto node:adjacencyList) {
            int neighbors = node.second.size();
            vector<bool> v(neighbors, false);
            visitedNeighbors[node.first] = v;

        }
        count = tickets.size() + 1;
        vector<string> currentPath;
        dfs("JFK", currentPath);

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