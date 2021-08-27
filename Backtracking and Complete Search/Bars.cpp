#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
//ACCEPTED

int arr[20];
int n, p;
int Count;

void solve(int pos, int sum) {
    if (pos == p || sum == n) {
        if (sum == n)
            Count++;
        return;
    }
        if (sum >= n)
            return;

        //pick
        sum += arr[pos];
        solve(pos + 1, sum);
        sum -= arr[pos];

        //leave
        solve(pos + 1, sum);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        for (int i = 0; i < p; i++)
            cin >> arr[i];
        Count = 0;
        solve(0, 0);
        if (Count != 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;

    }


    return 0;
}