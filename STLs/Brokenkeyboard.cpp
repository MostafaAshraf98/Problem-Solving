#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string str;
    while (cin >> str) {
        deque<string> ans;
        bool back = true;
        string x = "";
        for (int i = 0; i < str.length(); i++) // bamshy 3ala kol el letters eli fel kelma
        {

            if (str[i] == '[') { // law fata7t bracket
                if (!x.empty()) // law kan fih already kelma me5azenha ba7otaha ( w mesh hayebb2a fih kelma met5azena 8er law kont fate7 bracket [
                    ans.push_front(x);

                back = false; // a2oul eni bakteb front delwa2ti
                x.erase(0, x.size()); // afadi el kelma eli ana 7ateitha
                continue;
            }
            if (str[i] == ']') {
                if (!x.empty())
                    ans.push_front(x);

                back = true;
                x.erase(0, x.size());
                continue;

            }
            if (!back) {
                x.append(1, str[i]);
            } else {
                string x; // x is the variable in this scope ( it would be better to use another var name
                x = str[i];
                ans.push_back(x);
            }
        }
        if (!x.empty())
                ans.push_front(x);

        while (!ans.empty()) {
            cout << ans.front();
            ans.pop_front();
        }
        cout << endl;
    }
    return 0;
}

//Fekret el mas2ala eni ba3mel deque 3alashan a3raf a3mel push men odma w men wara
// ba3od a7ott men wara 3ady l 7ad ma yedous [ da ma3ah eni ha2oul eni hakteb men odam , fa ba3od a7ott eli hayektebo f string
// w bo7ott el string da fel ans awel ma yedous [ tani w da ma3nah eni habtedi akteb 33ala el shemal 5ales tani
// aw yedous ] da ma3nah eno yerga3 yekteb fel a5er
// aw en el string ye5las aslun