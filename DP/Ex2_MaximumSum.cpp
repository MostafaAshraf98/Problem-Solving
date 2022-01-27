#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int index;
    int rating;
    vector<Node *> children;
};


long long maximumSum(Node *root, vector<long long> &memo) {
    if (memo[root->index] != -1)
        return memo[root->index];

    if (root->children.empty())
        return memo[root->index] = root->rating;

    long long sumpick = root->rating;
    for (auto child:root->children)
        for (auto grandchild:child->children)
            sumpick += maximumSum(grandchild, memo);

    long long sumleave=0;
    for(auto child:root->children)
        sumleave+=maximumSum(child,memo);

    return memo[root->index]= max(sumpick,sumleave);

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    // Number of nodes in the tree
    int N;
    cin >> N;

    vector<Node *> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node;
        nodes[i]->index = i;
        cin >> nodes[i]->rating;
    }

    // Iterating over all edges
    int parent, child;
    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        nodes[parent]->children.push_back(nodes[child]);
    }

    vector<long long> memo(N, -1);
    cout << maximumSum(nodes[0], memo);

    return 0;
}