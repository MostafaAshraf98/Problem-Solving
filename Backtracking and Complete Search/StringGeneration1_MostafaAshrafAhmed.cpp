#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

bool checkValidity(vector<string> v, string str, int k) {
    int count = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        if (str.find(v[i]) != string::npos)
            count++;
        if (count == k)
            return true;
    }
    return false;
}

void solve(int m, vector<string> v, int n, string currentString, int k, int &count) {
    //state:
    //m: the number of strings (fixed)
    //v: the vector of strings (fixed)
    //n: the final length of the string we are generating (fixed)
    //currentString: the currentString so far (changes)
    //k : the least number of substrrings (fixed)
    //count: the final count (changes in base)

    //base:
    if ((int)currentString.length() == n) {
        if (checkValidity(v, currentString, k))
            count++;
        return;
    }

    //transistions
    //A
    solve(m, v, n, currentString + "A", k, count);

    //B
    solve(m, v, n, currentString + "B", k, count);

    //C
    solve(m, v, n, currentString + "C", k, count);

    //D
    solve(m, v, n, currentString + "D", k, count);

    //E
    solve(m, v, n, currentString + "E", k, count);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int m;// number of strings
    int n; // the length of new strings that you try to find
    int k;// the least number of substrings
    cin >> m >> n >> k;
    vector<string> v(m, "");
    for (int i = 0; i < m; i++)
        cin >> v[i];

    cin >> n >> m >> k;
    int count = 0;
    solve(m, v, n, "", k, count);
    cout << count << endl;
    return 0;
}