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

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == NULL)
            return NULL;
        Node *smallest = NULL;
        Node *largest = NULL;
        stack<Node *> s;
        vector<Node *> expanded;
        s.push(root);
        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            if (smallest == NULL || temp->val < smallest->val)
                smallest = temp;
            if (largest == NULL || temp->val > largest->val)
                largest = temp;

            if (temp->right != NULL)
                s.push(temp->right);
            if (temp->left != NULL)
                s.push(temp->left);

            //Get the Sucessor of this node
            Node *successor = temp->right;
            if (successor != NULL) {
                while (successor->left != NULL)
                    successor = successor->left;
                temp->right = successor;
                expanded.push_back(temp);
            }

            //Get the Sucessor of this node
            Node *predecessor = temp->left;
            if (predecessor != NULL) {
                while (predecessor->right != NULL)
                    predecessor = predecessor->right;
                temp->left = predecessor;
                expanded.push_back(temp);
            }
        }
        largest->right = smallest;
        smallest->left = largest;
        for (int i = 0; i < expanded.size(); i++) {
            expanded[i]->right->left = expanded[i];
            expanded[i]->left->right = expanded[i];

        }
        return smallest;
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