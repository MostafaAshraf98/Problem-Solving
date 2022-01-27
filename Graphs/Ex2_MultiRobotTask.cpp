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

class Task {
public:
    ll index; // the index of the task
    int color; //0 white, 1 gray, 2 black
    vector<Task *> precedingTasks;
};

stack<Task *> S;

void DFS_Visit(vector<Task *>& G, Task *u) {
    u->color = 1;
    for (auto v:u->precedingTasks) {
        if (v->color == 0) {
            DFS_Visit(G, v);
        }
    }
    S.push(u);
    u->color = 2; // set color as black
}

void DFS(vector<Task *>& G) {
    for (auto u : G) {
        if (u->color == 0)
            DFS_Visit(G, u);
    }
}



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
// #endif
    ll n; // the number of tasks
    cin >> n;
    vector<Task *> G(n,NULL);
    for (ll i = 0; i < n; i++) {
        Task *currentIndexTask = G[i];
        if (currentIndexTask == NULL) // if this task does not exist in the graph yet
        {
            //create a new task with this index
            currentIndexTask = new Task();
            currentIndexTask->index = i; // assign index
            currentIndexTask->color = 0; // the color is white
            G[i]=currentIndexTask;
        }
        for (int j = 0; j < 2; j++) {
            ll p;
            cin >> p;
            if (p != -1) {
                Task *prec = G[p];
                if (prec == NULL) {
                    prec = new Task();
                    prec->index = p; // assign index
                    prec->color = 0; // the color is white
                    G[p]=prec;
                }
                prec->precedingTasks.push_back(currentIndexTask);
            }
        }
    }
    DFS(G);
    while (!S.empty()) {

        Task *temp = S.top();
        cout << temp->index << " ";
        S.pop();
    }
    cout << endl;

    return 0;
}