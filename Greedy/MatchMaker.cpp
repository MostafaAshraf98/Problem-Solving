#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/contest/159/problem/B
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif

    map<int, int> countSizeMarkers;
    map<int, int> countColorMarkers;
    map<int, int> countSizeCaps;
    map<int, int> countColorCaps;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) // markers
    {
        ii x;
        cin >> x.second >> x.first;
        int number = x.second * 1000 + x.first;
        if (countSizeMarkers.find(x.first) != countSizeMarkers.end()) {
            countSizeMarkers[x.first]++;
        } else {
            countSizeMarkers[x.first] = 1;
        }
        if (countColorMarkers.find(number) != countColorMarkers.end()) {
            countColorMarkers[number]++;
        } else {
            countColorMarkers[number] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        ii x;
        cin >> x.second >> x.first;
        int number = x.second * 1000 + x.first;
        if (countSizeCaps.find(x.first) != countSizeCaps.end()) {
            countSizeCaps[x.first]++;
        } else {
            countSizeCaps[x.first] = 1;
        }
        if (countColorCaps.find(number) != countColorCaps.end()) {
            countColorCaps[number]++;
        } else {
            countColorCaps[number] = 1;
        }
    }
    int countClosed = 0;
    int countBeautifullyClosed = 0;

    for (auto it = countSizeMarkers.begin(); it != countSizeMarkers.end(); it++) {
        int numberMarkers = it->second;
        auto it2 = countSizeCaps.find(it->first);
        if (it2 != countSizeCaps.end())
            countClosed += min(numberMarkers, it2->second);
    }
    for (auto it = countColorMarkers.begin(); it != countColorMarkers.end(); it++) {
        int numberMarkers = it->second;
        auto it2 = countColorCaps.find(it->first);
        if (it2 != countColorCaps.end())
            countBeautifullyClosed += min(numberMarkers, it2->second);
    }
    cout << countClosed << " " << countBeautifullyClosed << endl;


    return 0;
}

//fekret el mas2ala eni ba3mel 2 maps lel markers w 2 maps lel caps 1 map for the size and its count and another is
// an identifier for the pair size and color and its count  w ashouf fih min kam cap w marker b nafs el size
// w fih kam cap w marker f nafs el size wel color