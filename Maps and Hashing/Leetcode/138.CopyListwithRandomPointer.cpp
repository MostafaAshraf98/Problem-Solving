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
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == NULL)
            return NULL;
        map<Node *, int> mp; // what is the index of the Node* in the key
        Node *start = head;
        int i = 0;
        while (start != NULL) {
            mp[start] = i;
            start = start->next;
            i++;
        }
        mp[NULL] = i;
        // every index represent the Node and the value is the index of the random node it is pointing at
        vector<int> v(i);
        start = head;
        i = 0;
        while (start != NULL) {
            v[i] = mp[start->random];
            start = start->next;
            i++;
        }
        vector<Node *> copy(i+1);
        copy[i]=NULL;
        start = head;
        for (int j = 0; j < i; j++) {
            Node *n = new Node(start->val);
            copy[j] = n;
            start = start->next;
        }
        for (int j = 0; j < i; j++) {
            copy[j]->next = copy[j + 1];
            copy[j]->random = copy[v[j]];
        }
        return copy[0];
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