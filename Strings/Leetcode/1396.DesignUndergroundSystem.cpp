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

//https://leetcode.com/problems/design-underground-system/
class UndergroundSystem {
public:
    map<int, pair<string, int>> checkedIn; // the key is the id of the customer, the pair is the station name and the time
    map<pair<string, string>, pair<int, int>> tripHistory; //key is from to , value.first is the total time, value.second is the count of trips

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        pair<string, int> p = make_pair(stationName, t);
        checkedIn[id] = p;
    }

    void checkOut(int id, string stationName, int t) {
        auto in = checkedIn[id];
        pair<string, string> key = make_pair(in.first, stationName);
        int time = t - in.second;
        if (tripHistory.find(key) == tripHistory.end()) // if this trip is the first time to do it
            tripHistory[key] = make_pair(time, 1);
        else {
            tripHistory[key].first += time;
            tripHistory[key].second++;
        }
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = tripHistory[make_pair(startStation, endStation)];
        return p.first / (double) p.second;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    return 0;
}