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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            pair<TreeNode *, int> currentNode = q.front();
            q.pop();
            if (currentNode.first->left != NULL)
                q.push(make_pair(currentNode.first->left, currentNode.second + 1));
                
            if (currentNode.first->right != NULL)
                q.push(make_pair(currentNode.first->right, currentNode.second + 1));

            if (currentNode.first->left == NULL && currentNode.first->right == NULL)
                return currentNode.second;
        }
        return 1;
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