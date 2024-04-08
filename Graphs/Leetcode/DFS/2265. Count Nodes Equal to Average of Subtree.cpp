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
    int answer = 0;
    pair<int, int> solve(TreeNode *currentNode)
    {
        int count = 1;
        int sum = currentNode->val;
        if (currentNode->left != NULL)
        {
            pair<int, int> left = solve(currentNode->left);
            sum += left.first;
            count += left.second;
        }

        if (currentNode->right != NULL)
        {
            pair<int, int> right = solve(currentNode->right);
            sum += right.first;
            count += right.second;
        }
        if (sum / count == currentNode->val)
            answer++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        solve(root);
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