#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/problemset/problem/673/B
//ACCPETED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n, m;
    cin >> n >> m;
    if (n <= 1) {
        cout << "0" << endl;
        return 0;
    }
    if (m == 0) {
        cout << n - 1 << endl;
        return 0;
    }
    set<int> Div1;
    set<int> Div2;
    ll minDiv1 = INF;
    ll maxDiv2 = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Div1.insert(max(x, y));
        Div2.insert(min(x, y));
        if (max(x, y) < minDiv1)
            minDiv1 = max(x, y);
        if (min(x, y) > maxDiv2)
            maxDiv2 = min(x, y);
        auto it = Div2.end();
        it--;
        if (*it >= minDiv1) {
            cout << "0" << endl;
            return 0;
        }
    }
    int unSet = minDiv1 - maxDiv2 - 1;
    int result = unSet + 1;
    cout << result << endl;
    return 0;
}

//fekret el mas2ala eni law 3andi problem wa7da aw a2al keda mesh ha3raf yeb2a at least one problem fel Div --> cout 0
// law mafish similar problem yeb2a 3andi n-1 ways eni awaza3 el problems --> e3mel simulation 3ala idak bas lazem kol Div yeb2a fiha wa7da
// 8er keda ma3 kol pair of similar problems ba7ott el as8ar f Div2 wel akbar f Div1 w law 7asal en eli 7ateito f div2 akbar men el min eli f Div1
// yeb2a there is no way eni a2asemhom 3alashan keda ya ella ha7ott 2 similar problems in same Div or eni a7ottf Div2 7aga more difficult than Div1
// lama a5alas hashouf as8ar 7aga f Div1 w akbar 7aga f Div1 w ashouf hal fih gap mabenhom wala la2
// law fih problems fa da ma3nah eni momken awaza3ha b kaza tari2a = minDIv1 = maxDiv2