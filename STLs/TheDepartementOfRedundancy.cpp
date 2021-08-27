#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=425
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    vector<ii> v;
    while (cin >> n) {
        bool inserted = false;
        for (int i = 0; i < v.size(); i++) {
            if (n == v[i].first) {
                v[i].second++;
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            v.push_back(make_pair(n, 1));
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}