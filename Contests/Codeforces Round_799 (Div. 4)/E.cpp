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

int solve(const vi &v, vector<vi> &memo, const int &s, int itFront, int itBack, int currentSum) {
    if (currentSum == s)
        return 0;
    if (itFront > itBack)
        return 10e6;
    if (memo[itFront][itBack] != -1)
        return memo[itFront][itBack];

    //transitions
    int front = 1 + solve(v, memo, s, itFront + 1, itBack, currentSum - v[itFront]);
    int back = 1 + solve(v, memo, s, itFront, itBack - 1, currentSum - v[itBack]);
    return memo[itFront][itBack] = min(front, back);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        int s;
        cin >> n >> s;
        vi v(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (sum < s) {
            cout << -1 << endl;
            continue;
        } else if (sum == s) {
            cout << 0 << endl;
            continue;
        }
        int itFront = 0;
        int itBack = n - 1;
        vector<vi> memo(n, vi(n, -1));
        cout << solve(v, memo, s, itFront, itBack, sum) << endl;
    }
    return 0;
}