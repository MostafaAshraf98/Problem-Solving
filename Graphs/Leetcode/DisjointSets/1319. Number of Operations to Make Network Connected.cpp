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

// Accepted
// Disjoint Sets

class UnionFind
{
private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    UnionFind(int size) : root(size), rank(size), count(size)
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    int getCount()
    {
        return count;
    }
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        UnionFind uf(n);
        int countAddOns = 0;
        for (vector<int> connection : connections)
        {
            if (uf.isConnected(connection[0], connection[1]))
                countAddOns++;
            else
                uf.unionSet(connection[0], connection[1]);
        }
        int countSets = uf.getCount();
        if (countAddOns >= countSets - 1)
            return countSets - 1;
        else
            return -1;
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