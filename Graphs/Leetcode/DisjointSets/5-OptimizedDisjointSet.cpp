#include <bits/stdc++.h>
using namespace std;

class UnionFind {

private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    // O(N)
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        count = sz;
    }
    // O(alpha * N)
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // O(alpha * N)
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

    // O(alpha * N)
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // O(1)
    int getCount() {
        return count;
    }
};