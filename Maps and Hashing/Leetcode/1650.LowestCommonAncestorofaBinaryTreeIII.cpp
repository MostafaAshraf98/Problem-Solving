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
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};


class Solution {
public:
    Node *lowestCommonAncestor(Node *p, Node *q) {
        map<Node*, bool> ancestorsP;
        map<Node*, bool> ancestrosQ;
        ancestorsP[p] = true;
        ancestrosQ[q] = true;

        while (p->parent != NULL || q->parent != NULL) {
            if (ancestorsP.find(q) != ancestorsP.end())
                return q;
            if (ancestrosQ.find(p) != ancestrosQ.end())
                return p;
            if (p->parent != NULL)
                p = p->parent;
            if (q->parent != NULL)
                q = q->parent;
            ancestorsP[p] = true;
            ancestrosQ[q] = true;
        }
        return p;
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