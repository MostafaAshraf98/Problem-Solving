#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=481
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    int scenario = 1;
    while (cin >> t && t != 0) {
        vector<ii> v;
        vector<ii> teams;
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                teams.push_back(make_pair(x, i));
            }
        }// Now we have vector of pairs(teams)
        string str;
        cout << "Scenario #" << scenario << endl;
        while (cin >> str && str != "STOP") {
            if (str == "ENQUEUE") {
                int x;
                cin >> x;
                int teamNb = -1;
                // identify which team it belongs to (if it belongs to any)
                for (int i = 0; i < teams.size(); i++) {
                    if (teams[i].first == x) {
                        teamNb = teams[i].second;
                        break;
                    }
                }
                //if it has no teams , enqueue at the end
                if (teamNb == -1)
                    v.push_back(make_pair(x, -1));
//if it has team
                else {
                    // check if its team already exists in the vector
                    bool inserted = false;
                    for (int i = 0; i < v.size() - 1; i++) {
                        if (v.empty())
                            break;
                        if ((v[i].second == teamNb && v[i + 1].second != teamNb)) {
                            v.insert(v.begin() + i + 1, make_pair(x, teamNb));
                            inserted = true;
                            break;
                        }
                    }
                    if (!inserted) {
                        v.push_back(make_pair(x, teamNb));
                    }
                }
            } else // it is dequeue
            {
                cout << v.front().first << endl;
                v.erase(v.begin());
            }
        }
        cout << endl;
        scenario++;
    }

    return 0;
}
//Fekret el mas2ala eni ba7ott kol el teams eli beyda5alha f vector of pairs fih el rakam wel team beta3o
// ba3d keda law enqueue .. bashouf awel 7aga hal el rakam da lih team wala la2, law maloush ba3melo pushback fel ecotr ans
// law lih team .. bamshy 3ala vector of ans bashouf fein wa2ef a5er wa7ed mel teams beta3o ( law mafish 7ad mel team beta3 .. aw wa2fin a5er nas
// by default beyet7att a5er wa7ed