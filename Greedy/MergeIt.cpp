#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//  https://codeforces.com/problemset/problem/1176/B
//  ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int countNumbers = 0;
        int countOnes = 0;
        int countTwos = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 3 == 0)
                countNumbers++;
            else if (x % 3 == 1)
                countOnes++;
            else
                countTwos++;
        }

        int countPairs= min(countOnes,countTwos);
        countNumbers += countPairs;

        countOnes-=countPairs;
        countTwos-=countPairs;

        countNumbers+=countOnes/3;
        countNumbers+=countTwos/3;

        cout << countNumbers << endl;
    }
    return 0;
}
// fekret el mas2ala en ay rakam 3andi haykoun case men 3 cases: yaela divisible by 3 (%3=0) ya ela remainder =1 ya ela el remainder =2
// fa law kan divisible hazawed el count
// 8er keda ha3od a3edd el numbers eli el rem =1 welli el rem =2
// ba5od rakam men el rem=1 w rakam men el rem=2 w agma3hom 3ala ba3d hayedouni rakam divisible by 3
//w da ma3nah el min of the two counts ... keda hayetba2ali shewaet arkam men el rem=1 or men el rem=2
// hashouf ha3raf agama3 kam rakam 3ala ba3d yedouni rakam divisible by 3 (kol 3 arkam men rem=1 or rem=2 yedouni rakam divisible by 3)