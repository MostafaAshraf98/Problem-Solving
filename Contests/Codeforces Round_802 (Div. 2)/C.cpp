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
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        ll target = v[0];
        ll currentCount = 0;
        ll p = 0;
        for (int i = 1; i < n; i++) {
            ll delta = v[i] - currentCount - target;
            if (delta == 0)
                continue;
                // if delta is positive then the current number is greater than the target -->
                // then we want to decrement the current number --> decrement all the upcoming numbers
            else if (delta > 0) {
                currentCount += abs(delta);
                // if delta is negative then the current number is less than the target
                // we want to decrement the target target + delta and delta is negative

            } else {
                target += delta;
                p += abs(delta);
            }
        }
        int answer = currentCount + abs(target) + p;
        cout << answer << endl;
    }
    return 0;
}