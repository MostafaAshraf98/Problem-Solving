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
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        count = sz;
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        UnionFind uf(s.size());
        for (int i = 0; i < pairs.size(); i++) {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }
        unordered_map<int, vector<char>> letters;
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < s.size(); i++) {
            int root = uf.find(i);
            char letter = s[i];
            letters[root].push_back(letter);
            indices[root].push_back(i);
        }
        for(auto it=letters.begin();it!=letters.end();it++)
        {
            int root = it->first;
            auto letters = it->second;
            sort(letters.begin(),letters.end());
            auto ind = indices[root];
            for(int i=0;i<ind.size();i++)
            {
                s[ind[i]] = letters[i];
            }
        }
        return s;
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