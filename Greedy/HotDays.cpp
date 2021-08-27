#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/problemset/problem/215/D
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    double numRegions, numStudents;
    scanf("%lf %lf", &numRegions, &numStudents);
    ll total = 0;
    for (int i = 0; i < numRegions; i++) {
        ll temperature, maxTemp, compensation, cost;
        bool comp = false;
        scanf("%lld %lld %lld %lld", &temperature, &maxTemp, &compensation, &cost);
        int numberOfBuses = ceil(numStudents / (maxTemp - temperature));
        if (maxTemp <= temperature)
            comp = true;
        if (temperature + numStudents <= maxTemp)
            total += cost;
        else if (!comp && (numberOfBuses * cost < (compensation * numStudents)+cost)) {
            total += numberOfBuses * cost;
        } else {
            total += compensation * numStudents + cost;
        }

    }
    printf("%lld\n", total);
    return 0;
}

//fekret el mas2ala eni bashouf f kol region a7san case .. there are 3 cases ...
// 1- eni ma7tagsh adfa3 8er felous el bus
// w 3adad el children plus el temp as8ar or equal el Maxtemp f mesh ha7tag adfa3 compensation
// 2- eni akarar asta8dem 3adad buses ye5alini madfa3sh ay compensation w mesh halga2 lel 7all da
// 8er law mesh hadfa3 comp (comp = false) w kaman eno yeb2a ar5as men eni adfa3 comp
// 3- eni a2a3ad all students in same bus w adfa3 compensation