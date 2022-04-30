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

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        if (head == NULL)
            return NULL;
        Node *first = head;
        stack<Node *> s;
        while (head->next != NULL || head->child != NULL || !s.empty()) {
            if (head->next == NULL && head->child == NULL) {
                Node *next = s.top();
                s.pop();
                head->next = next;
                next->prev = head;
                head = next;
            } else if (head->child != NULL) {
                if (head->next != NULL)
                    s.push(head->next);
                Node *temp = head->child;
                head->next = temp;
                temp->prev = head;
                head->child = NULL;
                head = temp;
            } else {
                head = head->next;
            }

        }
        return first;
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