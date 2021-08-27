#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, x;
    while (cin >> n && n != 0) {
        vector<set<int>> v; // vector of different unique combinations
        vi popularity; // corresponding nb of students that took such combination
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int i = 0; i < 5; i++) // make a set of the combination of this student
            {
                cin >> x;
                s.insert(x);
            }
            bool found = false;
            for (int i = 0; i < v.size(); i++) // compare this set with previous sets
            {
                auto it1 = s.begin();
                auto it2 = v[i].begin();
                int diff = 0;
                for (int j = 0; j < 5; j++) {
                    if (*it1 != *it2) { // if it differs from this combination
                        diff = 1;
                        break;
                    }
                    it1++;
                    it2++;
                }
                if (diff == 0) { // if it is the same as this combination
                    popularity[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) { // if this was a new combination
                v.push_back(s);
                popularity.push_back(1);
            }
        }
        int max = *max_element(popularity.begin(), popularity.end()); // get the max populatiry
        int count = 0;
        for (int i = 0; i < popularity.size(); i++) {
            if (popularity[i] == max) // if there is more than 1 combination with max populatiry we add them up
                count += max;
        }
        cout << count << endl;

    }
    return 0;
}