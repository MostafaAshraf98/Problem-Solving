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
    vector<bool> visited;
    int n;

    int getTreeMin(TreeNode *root)
    {
        while (root->left != nullptr)
            root = root->left;
        return root->val;
    }

    int getTreeMax(TreeNode *root)
    {
        while (root->right != nullptr)
            root = root->right;
        return root->val;
    }

    vector<TreeNode *> solve(int index)
    {
        vector<TreeNode *> answer;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                vector<TreeNode *> result = solve(i);
                visited[i] = false;
                for (TreeNode *tree : result)
                {
                    TreeNode *currentIndex = new TreeNode(index);
                    if (tree->val < index && getTreeMax(tree) < index)
                        currentIndex->left = tree;

                    else if (tree->val > index && getTreeMin(tree) > index)
                        currentIndex->right = tree;
                    else
                        continue;
                    answer.push_back(currentIndex);
                }
            }
        }

        if (answer.size() == 0)
        {
            TreeNode *currentIndex = new TreeNode(index);
            answer.push_back(currentIndex);
        }

        return answer;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> answer;
        if (n == 0)
            return answer;

        if (n == 1)
        {
            TreeNode *first = new TreeNode(1);
            answer.push_back(first);
            return answer;
        }

        this->n = n;
        visited = vector<bool>(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            visited[i] = true;
            vector<TreeNode *> result = solve(i);
            visited[i] = false;
            for (TreeNode *tree : result)
                answer.push_back(tree);
        }
        return answer;
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