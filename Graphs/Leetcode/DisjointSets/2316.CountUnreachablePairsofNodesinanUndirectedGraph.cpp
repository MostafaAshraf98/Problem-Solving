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

class UnionFind {

private:
    vector<int> root;
    vector<int> rank;
    int count;

public:

    UnionFind(int size) : root(size), rank(size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        count = size;
    }

    int find(int x) {
        if (root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if (rank[rootY] > rank[rootX])
                root[rootX] = rootY;
            else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() {
        return count;
    }

    void countElementsInComponent(unordered_map<int, int> &mp) {
        for (int i = 0; i < root.size(); i++) {
            int rootI = find(i);
            if (mp.find(rootI) == mp.end())
                mp[rootI] = 1;
            else
                mp[rootI]++;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        for (vector<int> edge:edges) {
            uf.unionSet(edge[0], edge[1]);
        }
        unordered_map<int, int> mp;
        uf.countElementsInComponent(mp);
        long long result = 0;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            result += n - mp[root];
        }
        return result / 2;
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