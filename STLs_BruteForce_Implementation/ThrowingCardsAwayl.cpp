#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while (cin >> n && n != 0) {
        queue<int> Q;
        queue<int> discarded;
        for (int i = 1; i <= n; i++)
            Q.push(i);
        while (Q.size() != 1) {
            discarded.push(Q.front());
            Q.pop();
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        };
        cout << "Discarded cards:";
        while (!discarded.empty()) {
            cout << " " << discarded.front();
            if (discarded.size() != 1)
                cout << ",";
            discarded.pop();
        }
        cout << endl;
        cout << "Remaining card: " << Q.front();
        cout << endl;
    }
    return 0;
}