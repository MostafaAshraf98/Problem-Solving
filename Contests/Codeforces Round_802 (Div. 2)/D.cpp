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
const ll N = (ll) 10e4;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    ll n; // the number of locks
    cin >> n;
    ll tmin = LONG_LONG_MIN; // The idea minimum time to fill all the tanks
    vector<ll> v(n); // The volumes of locks
    vector<ll> sv(n, 0); // The prefix sum, the sum of all the volums from 0 up to i
    vector<ll> tt(n,
                  0); // The time taken to fill first k locks by k pipes where k is the index and the value is the time
    vector<ll> pt(
            n); // Amount of time to fill all the tanks with k pipes , where k is the index and the value is the time
    for (ll i = 0; i < n; i++) {
        cin >> v[i];

        // Update the Prefix Sum
        if (i == 0)
            sv[i] = v[i];
        else
            sv[i] = sv[i - 1] + v[i];

        // Update tmin
        if (sv[i] > tmin * (i + 1)) {
            tmin = ceil((double) sv[i] / (i + 1));
        }
        if (i == 0) {
            tt[i] = ceil((double) sv[i] / (i + 1));
        } else {
            tt[i] = max(tt[i - 1], (ll)ceil((double) sv[i] / (i + 1)));
        }
    }
    for (int i = 0; i < n; i++) {
        ll temp;
        temp = ceil((double) sv[n - 1] / (i + 1));
        pt[n - 1 - i] = max(temp, tt[i]);
    }

    ll q; // the number of queries
    cin >> q;
    while (q--) {
        ll t; // The required Time
        cin >> t;
        if (t < tmin) {
            cout << -1 << endl;
        } else if (t >= sv[n - 1]) {
            cout << 1 << endl;
        } else {
            auto upper = upper_bound(pt.begin(), pt.end(), t);
            cout << n - (upper - pt.begin()) + 1 << endl;
        }
    }

    return 0;
}