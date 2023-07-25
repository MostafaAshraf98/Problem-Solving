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

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;

        if (root == NULL)
            return result;

        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        vector<int> v;
        v.push_back(root->val);
        result.push_back(v);

        while (!q.empty())
        {
            vector<int> v;
            int queueSize = q.size();

            Node *currentNode = q.front().first;
            int level = q.front().second;

            q.pop();

            vector<Node *> children = currentNode->children;

            for (Node *child : children)
            {
                if (result.size() == level + 1)
                {
                    vector<int> v;
                    result.push_back(v);
                }
                result[level + 1].push_back(child->val);
                q.push(make_pair(child, level + 1));
            }
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