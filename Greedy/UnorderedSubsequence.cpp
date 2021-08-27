#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
//#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/problemset/problem/27/C
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n;
    vi indices;
    cin >> n;
    if (n <= 2)
    {
        cout << "0" << endl;
        return 0;
    }

    int x;
    cin >> x;
    int length = 1;
    indices.push_back(1);
    bool searchGreater;
    int valueLast=x;
    int i = 2;

    while (indices.size() != 2 && i <= n) {
        i++;
        cin >> x;
        if (x == valueLast)
            continue;
        else if (x > valueLast) {
            searchGreater = false;
        } else
            searchGreater = true;
        valueLast = x;
        indices.push_back(i-1);
        length++;
    }
    for (; i <= n; i++) {
        cin >> x;
         if (x > valueLast && searchGreater == true) {
            length++;
            indices.push_back(i);
            searchGreater = false;
        } else if (x > valueLast && searchGreater == false) {
            indices.pop_back();
            indices.push_back(i);
        } else if (x < valueLast && searchGreater == false) {
            length++;
            indices.push_back(i);
            searchGreater = true;
        } else if (x < valueLast && searchGreater == true) {
            indices.pop_back();
            indices.push_back(i);
        }
        valueLast = x;

    }
    if (length <= 2) {
        cout << "0" << endl;
        return 0;
    }
    cout << 3 << endl;

    for (int i = 0; i < 3; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
    return 0;
}