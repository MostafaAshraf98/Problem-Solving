#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    getline(cin, str);
    while (t--) {
        int row = 1;
        int answerRow;
        int answerCol;
        int found = false;
        while (getline(cin, str) && str != "") {
            vector<int> cols;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '#') {
                    cols.push_back(i + 1);
                }
            }

            if (cols.size() == 2 && !found) {
                answerCol = (cols[0] + cols[1]) / 2;
                answerRow = row + ceil((cols[1] - cols[0]) / 2.0);
                found = true;
            }
            row++;
        }
        cout << answerRow << " " << answerCol << endl;
    }
    return 0;
}