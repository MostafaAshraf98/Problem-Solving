#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int d;
    while (cin >> d && d != 0) {
        multiset<int> s;
        ll count = 0;
        for (int k = 0; k < d; k++) {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                s.insert(x);
            }
            count += (*(--s.end()) - *s.begin());
            s.erase(s.begin());
            s.erase(--s.end());
        }
        cout << count << endl;
    }

    return 0;
}