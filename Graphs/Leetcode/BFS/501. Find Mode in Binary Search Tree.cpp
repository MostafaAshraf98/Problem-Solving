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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        unordered_map<int, int> mp;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *currentNode = q.front();
            q.pop();
            if (mp.find(currentNode->val) == mp.end())
                mp[currentNode->val] = 1;
            else
                mp[currentNode->val]++;

            if (currentNode->right != NULL)
                q.push(currentNode->right);

            if (currentNode->left != NULL)
                q.push(currentNode->left);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (auto it : mp)
            pq.push({it.second, it.first});

        int mostFreq = pq.top().first;
        while (!pq.empty())
        {
            int count = pq.top().first;
            int val = pq.top().second;
            pq.pop();

            if (count != mostFreq)
                break;
            result.push_back(val);
        }
        return result;
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