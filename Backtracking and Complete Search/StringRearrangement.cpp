#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define endl '\n';
#define INF 10e8;

int stringsLenght = 0;

bool checkIdentical(vector<string> v) {
    for (int i = 1; i < (int) v.size(); i++) {
        if (v[i] != v[i - 1])
            return false;
    }
    return true;
};

void moveLetter(string &s) {
    string temp = s;
    s.erase(0, 1);
    s = s + temp[0];
}

void solve(int n, vi countMovedTimes, vector<string> v, int countMoves, int &minCount) {
    //state:
    //n: the number of strings in the vector (fixed)
    //v: the  vector of strings (in this state) (changes with every move)
    //countMoves: the number of moves so far
    //minCount: the best count so far

    //base
    if (checkIdentical(v)) {
        if (countMoves < minCount || minCount == -1)
            minCount = countMoves;
        return;
    }
    if (countMoves >= minCount && minCount != -1) // proning
        return;
    //transition
    for (int i = 0; i < n; i++) // looping over the strings
    {
        //apply move on every string of the vector of strings
        if (countMovedTimes[i] == (stringsLenght - 1)) // if i return to the initial string
            continue;

        string temp = v[i];
        moveLetter(v[i]);
        countMovedTimes[i]++;

        solve(n, countMovedTimes, v, countMoves + 1, minCount);

        countMovedTimes[i]--;
        v[i] = temp;
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n; // number of strings
    cin >> n;
    vector<string> str;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    stringsLenght = str[0].length();
    int minCount = -1;
    vi countMovedTimes(n, 0);
    solve(n, countMovedTimes, str, 0, minCount);
    cout << minCount << endl;
    return 0;
}