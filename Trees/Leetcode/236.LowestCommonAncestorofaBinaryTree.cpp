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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *parent;

};

class Solution {
public:
    bool
    Traversal(TreeNode *node, const TreeNode *p, const TreeNode *q, TreeNode *&commonAncestor) {
        if (node == NULL)
            return false;
        if (commonAncestor != NULL)
            return false;
        int mid = 0;
        if (node == p || node == q)
            mid = 1;
        bool found1 = Traversal(node->right, p, q, commonAncestor);
        bool found2 = Traversal(node->left, p, q, commonAncestor);

        int total = mid + found1 + found2;
        if (total == 2) {
            if (commonAncestor == NULL)
                commonAncestor = node;
            return true;
        } else if (total == 1)
            return true;
        else
            return false;

    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        TreeNode *commonAncestor = NULL;
        Traversal(root, p, q, commonAncestor);
        return commonAncestor;
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