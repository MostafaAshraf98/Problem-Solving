
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
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int n; // the number of challenges
    cin >> n;
    ll totalPenalityCount = 0;
    multiset<ll> attendedChallengesPenalities;
    vector<pair<ll, ll>> deadlinePenality(n);
    for (int i = 0; i < n; i++)
        cin >> deadlinePenality[i].first;
    for (int i = 0; i < n; i++)
        cin >> deadlinePenality[i].second;

    sort(deadlinePenality.begin(), deadlinePenality.end());

    ll time = 1;
    int i = 0;
    while (i < n) {
        if(time<=deadlinePenality[i].first)
        {
            attendedChallengesPenalities.insert(deadlinePenality[i].second);
            i++;
            time++;
            continue;
        }
        else
        {
            //see if we have attended a challenge with a lower penality
            if (!attendedChallengesPenalities.empty() &&
                *attendedChallengesPenalities.begin() < deadlinePenality[i].second) {
                totalPenalityCount += *attendedChallengesPenalities.begin();
                attendedChallengesPenalities.insert(deadlinePenality[i].second);
                attendedChallengesPenalities.erase(attendedChallengesPenalities.begin());
            } // else this means that so far all the challenges we attended have larger penality so we will not be able to attend this one
            else {
                totalPenalityCount += deadlinePenality[i].second;
            }

        }
        i++;
    }
    cout << totalPenalityCount << endl;
    return 0;
}