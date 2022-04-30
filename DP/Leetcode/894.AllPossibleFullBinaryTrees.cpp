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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<TreeNode *> solve(int remainingNodes, map<int, vector<TreeNode *>> & memo) {
        if (memo.find(remainingNodes) != memo.end())
            return memo[remainingNodes];
        vector<TreeNode *> ans;
        if (remainingNodes == 1)
            ans.push_back(new TreeNode(0));
        else if (remainingNodes % 2 == 1) // if it is not even
        {
            //then we add the node and left and right binary Trees
            for (int x = 0; x < remainingNodes; x++) {
                int y = remainingNodes - 1 - x; // -1 because we add the root
                //where x is the number of nodes in the left subtree and y is the number of noces in the right subtree
                for (TreeNode *left  : solve(x,memo)) {
                    for (TreeNode *right : solve(y,memo)) {
                        TreeNode *bns = new TreeNode(0);
                        bns->left = left;
                        bns->right = right;
                        ans.push_back(bns);
                    }
                }
            }
        }
        return memo[remainingNodes] = ans;


    }

    vector<TreeNode *> allPossibleFBT(int n) {
        map<int, vector<TreeNode *>> memo;
        return solve(n, memo);
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