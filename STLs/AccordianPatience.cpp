#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=63&mosmsg=Submission+received+with+ID+26094182
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string str;
    while (cin >> str && str[0] != '#') {
        vector<stack<string>> v;
        stack<string> s;
        s.push(str);
        int k = 1; // iterator on vector
        v.push_back(s);
        for (int i = 0; i < 51; i++) {
            stack<string> s;
            cin >> str;
            s.push(str);
            v.push_back(s);
            k = v.size() - 1;
            while (k >= 0 &&k!=v.size()) {
                if (k - 3 >= 0) {
                    if (v[k - 3].top()[0] == v[k].top()[0] || v[k - 3].top()[1] == v[k].top()[1]) {
                        str = v[k].top();
                        v[k].pop();
                        v[k - 3].push(str);
                        if (v[k].size() == 0)
                            v.erase(v.begin() + k);
                        k -= 3;
                        continue;
                    }
                }
                if (k - 1 >= 0) {
                    if (v[k - 1].top()[0] == v[k].top()[0] || v[k - 1].top()[1] == v[k].top()[1]) {
                        str = v[k].top();
                        v[k].pop();
                        v[k - 1].push(str);
                        if (v[k].size() == 0)
                            v.erase(v.begin() + k);
                        k--;
                    } else
                        k++;
                } else
                    k++;
            }
        }
        if (v.size() != 1)
            cout << v.size() << " " << "piles remaining: ";
        else
            cout << "1 pile remaining: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].size();
            if (i + 1 != v.size())
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
// Fekret el mas2ala eni ba simulate eli beye7sal
// awel 7aga 3andi vecotr of pairs fih el card eli 3ala el wesh w 3adad el cards eli fel pile di
// ba7ott awel card .. ba3d keda bafta7 loop a3ad a7ott card by card
// awel ma a7ott card ba-check law eli ablo b 3 steps fe3lan shabaho
// fa barga3 wara 3 steps w a7ott el card 3ala el wesh w azawed el pile
// law la2 ba3mel nafs el kalam 3ala wa7ed mel left
// fekret el triedOne and TriedThree howa eni baboss 3ala el yemin ba3d mayeb2ash fih 7aga 3ala el shemal 5alas
// bema en el ta7arokat eli 3amaltaha momken tekoun sabebet en 7agat tani tezhar fa di eli bet8atiha