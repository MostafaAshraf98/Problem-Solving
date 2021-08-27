#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1236
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    cin >> m >> n;
    vector<pair<string, int>> Dictionary;
    for (int i = 0; i < m; i++) {
        pair<string, int> x;
        cin >> x.first >> x.second;
        Dictionary.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        string str;
        int salary = 0;
        while (cin >> str && str != ".") {

            if (str[0] < 'a' || str[0] > 'z')
                str.erase(0, 1);
            if (str[str.length() - 1] < 'a' || str[str.length() - 1] > 'z')
                str.erase(str.length() - 1, 1);

            for (int i = 0; i < m; i++) {
                if (Dictionary[i].first == str)
                    salary += Dictionary[i].second;
            }
        }
        cout << salary << endl;
    }
    return 0;
}