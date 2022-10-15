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
    int n; // the number of locks
    cin >> n;
    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (i == 0)
            sum[i] = temp;
        else
            sum[i] = sum[i - 1] + temp;
    }
    vector<ll> dp(n + 1); // how long it will take to fill the first i locks if the first i pipes are open
    dp[0] = LONG_LONG_MAX;
    dp[1] = sum[1];
    // Time = total Volume required / number of pipes functioning
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], (ll) ceil((double) sum[i] / i));
    }

    vector<ll> v(n + 1); // Time to fill all gates if ith pipes are open
    for (ll i = 0; i <= n; i++) {
        v[i] = max(dp[i], (ll) ceil((double) sum[sum.size() - 1] / i));
    }

    int q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        ll st = 0;
        ll end = n;
        if (v[v.size() - 1] > t) {
            cout << -1 << endl;
            continue;
        }
        while (st < end) {
            ll mid = st + (end - st) / 2;
            if (v[mid] <= t)// valid
                end = mid;
            else
                st = mid + 1;
        }
        cout << st << endl;
    }

    return 0;
}