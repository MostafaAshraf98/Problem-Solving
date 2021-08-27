#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    string x;
    getline(cin,x);
    getline(cin,x);
    while (n--) {
        string line;
        map<string, double> list;
        int count = 0;

        while (getline(cin,line) && line.length()!=0) {
            count++;
            if (list.find(line) == list.end())
                list[line] = 1;
            else
                list[line]++;
        }
        for (auto v: list)
            cout << v.first << " " << fixed << setprecision(4) << (v.second / count)*100 << endl;

        if(n ==0)
            continue;
            cout << endl;
    }
    return 0;
}