#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

void solve(int n, vector<string> v, string previous, vector<bool> taken, int index, int &count) {
    //state:
    //n: the number of names
    //v: the vector of names
    //taken: if this person has already seated or not
    //index: the current index of the seat

    //base
    if (index == n)
        count++;

    //transition
    for (int i = 0; i < n; i++) {//try to sit all the people
        if (index != 0 && (taken[i]==1 || previous[previous.length() - 1] == v[i][0])) {
            continue;
        }
        taken[i] = true;
        string temp = previous;
        previous = v[i];
        index++;
        solve(n, v, previous, taken, index, count);

        taken[i] = false;
        previous = temp;
        index--;

    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n; // number of names
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int count = 0;
    vector<bool> taken(n, false);
    solve(n,v,"",taken,0,count);
    cout << count << endl;

    return 0;
}