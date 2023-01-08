#include <bits/stdc++.h>
using namespace std;

class UnionFind {

private:
    vector<int> root; // size of this vector is n

public:

    //Ctor: Initially, Make the root of every node itself
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    // Quick Find O(1)
    int find(int x) {
        return root[x];
    }

    // Union O(n)
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        // If these two nodes are not in the same set
        if (rootX != rootY) {
            // Loop over all the nodes and make the root of all the nodes in the same set as y have the same root of x
            for (int i = 0; i < root.size(); i++) {
                if (root[i] == rootY) {
                    root[i] = rootX;
                }
            }
        }
    }

    // Checks whether these 2 nodes are connected or not
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}