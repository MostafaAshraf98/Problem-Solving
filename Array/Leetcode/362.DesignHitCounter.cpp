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

class HitCounter {
public:
    map<int, int> timestampCount;

    HitCounter() {

    }

    void hit(int timestamp) {
        if (timestampCount.find(timestamp) == timestampCount.end()) // this time stamp does not exist
        {
            timestampCount[timestamp] = 1;
        } else {
            timestampCount[timestamp]++;
        }
    }

    int getHits(int timestamp) {
        if (timestampCount.empty())
            return 0;
        int totalCount = 0;
        for (auto t = --timestampCount.end(); t != timestampCount.begin(); t--) {
            if (t->first + 300 > timestamp)
                totalCount += t->second;
            else
                break;
        }
        if (timestampCount.begin()->first + 300 > timestamp)
            totalCount += timestampCount.begin()->second;
        return totalCount;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}