#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int n; // the size of the array
    int d; //the difference
    int m; // the size of the subsequence
    cin >> n >> d >> m;
    unordered_map<int, int> mp; //this map keeps count of each value at this current index
    int count = 0;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (mp.find(x) == mp.end()) {
            mp[x] = 1;
        } else {
            mp[x]++;
        }
        if (m == 2) {
            int requiredBefore = x - d;
            if (mp.find(requiredBefore) != mp.end()) {
                count += mp.find(requiredBefore)->second;
            }
        } else // m==3
        {
            int requiredBefore = x - d;
            int requiredbeforeBefore = x - d - d;
            if (mp.find(requiredBefore) != mp.end() && mp.find(requiredbeforeBefore) != mp.end()) {
                int innerCount = 0;
                int CountRequiredBefore = 0;
                int CountRequiredBeforeBefore = 0;
                for (int j = 0; j < i; j++) {
                    if (v[j] == requiredbeforeBefore) {
                        CountRequiredBeforeBefore++;
                    } else if (v[j] == requiredBefore) {
                        innerCount +=
                                (mp.find(requiredBefore)->second - CountRequiredBefore) * CountRequiredBeforeBefore;
                        CountRequiredBeforeBefore = 0;
                        CountRequiredBefore++;
                    }
                }
                count += innerCount;
            }
        }
    }

    cout << count << endl;
    return 0;
}

