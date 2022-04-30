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
    string url;
    Node *previous;
    Node *next;
};

class BrowserHistory {
public:
    Node *current;

    BrowserHistory(string homepage) {
        current = new Node();
        current->url = homepage;
        current->previous = NULL;
        current->next = NULL;

    }

    void visit(string url) {
        Node *newurl = new Node();
        newurl->url = url;
        newurl->previous = current;
        newurl->next = NULL;
        current->next = newurl;
        current = current->next;

    }

    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->previous != NULL)
                current = current->previous;
            else
                return current->url;
        }
    }

    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->next != NULL)
                current = current->next;
            else
                return current->url;
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}