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

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    Node *dfs(Node *currentNode, unordered_map<Node *, Node*>& visited) {
        if (visited.find(currentNode) != visited.end())
            return visited[currentNode];

        Node* NewNode = new Node(currentNode->val);
        visited[currentNode]=NewNode;
        vector<Node *> neighbors = currentNode->neighbors;
        for (Node *neighbor: neighbors) {
            Node* newNeighbor = dfs(neighbor,visited);
            NewNode->neighbors.push_back(newNeighbor);
        }
        return NewNode;
    }

public:
    Node *cloneGraph(Node *node) {
        if (node == NULL)
            return NULL;

        if (node->neighbors.size() == 0) {
            Node * n= new Node(1);
            return n;
        }
        unordered_map<Node*,Node*> visited;
        return dfs(node,visited);

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