#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1223
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char line[100];
    char str[30];
    map<string, string> mp;

    while (gets(line) && line[0] != '\0') {
        char word1[30];
        char word2[30];
        sscanf(line, "%s %s", word1, word2);
        mp[word2] = word1;
    }

    while (gets(line)) {
        sscanf(line, "%s", str);
        if (mp[str] == "") { cout << "eh" << endl; }
        else
            cout << mp[str] << endl;
    }

    return 0;
}