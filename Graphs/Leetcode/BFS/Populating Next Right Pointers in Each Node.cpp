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

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if(root ==NULL)
            return root;

        queue<Node *> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();

            Node *temp1 = q.front();
            q.pop();

            if (temp1->left != NULL)
            {
                q.push(temp1->left);
                q.push(temp1->right);
            }

            for (int i = 1; i < size; i++)
            {
                Node *temp2 = q.front();
                q.pop();

                temp1->next = temp2;
                temp1 = temp2;
                if (temp2->left != NULL)
                {
                    q.push(temp1->left);
                    q.push(temp2->right);
                }
            }
        }
        return root;
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