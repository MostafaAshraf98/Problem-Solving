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

class Solution {
public:
    Node *connect(Node *root) {
        if(root ==NULL || root->left == NULL)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int lenElementsInQ = q.size();
            Node *prevNode = NULL;
            while (lenElementsInQ != 0) {
                Node *currentNode = q.front();
                q.pop();
                if (currentNode->left != NULL) {
                    Node *leftChild = currentNode->left;
                    Node *rightChild = currentNode->right;
                    q.push(leftChild);
                    q.push(rightChild);
                }
                if (prevNode != NULL)
                    prevNode->next = currentNode;
                prevNode = currentNode;
                lenElementsInQ--;
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