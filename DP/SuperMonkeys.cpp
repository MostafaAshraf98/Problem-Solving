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

ii addPair(ii x, ii y) {
    return make_pair(x.first + y.first, x.second + y.second);
}

ii getBestTry(vii &alltries, int totalNumBananas) {
    ii bestAns = make_pair(-1, -1);
    for (int i = 0; i < alltries.size(); i++) {
        if (bestAns.first == -1) // there is no best answer yet
            bestAns = alltries[i];
        if (alltries[i].first > bestAns.first) // ana wakol 3adad bananas aktar
            bestAns = alltries[i];
        if (alltries[i].first == bestAns.first) // same remaining
        {
            if (alltries[i].second < bestAns.second) // there is lest number of bites
                bestAns = alltries[i];
        }
    }
    return bestAns;

};

// me7tag araga3 7agtein the min remaining number of bananas in the bucket and the least number of bites to achieve that
ii solve(const int totalInBucket, int numBananasInBucket, vi &monkeysBites, vii &memo) {
    if (memo[numBananasInBucket] != make_pair(-1, -1))
        return memo[numBananasInBucket];
    if (numBananasInBucket == 0) {
        return memo[numBananasInBucket] = make_pair(0, 0);
    }
    //loop over monkeys and each one tries to bite this bucket


    vii alltries;
    for (int i = 0; i < monkeysBites.size(); i++) {
        if (monkeysBites[i] > numBananasInBucket || monkeysBites[i]==0) // invalid
            continue;
        alltries.push_back(addPair(make_pair(monkeysBites[i], 1),
                                   solve(totalInBucket, numBananasInBucket - monkeysBites[i], monkeysBites, memo)));

    }
    ii result = getBestTry(alltries, numBananasInBucket);
    if (result == make_pair(-1, -1)) // there is no bites at all
    {
        return memo[numBananasInBucket] = make_pair(0, 0);
    } else
        return memo[numBananasInBucket] = result;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
// #endif
    int n; // the number fo buckets
    cin >> n;
    vi buckets(n); // vector holding the number of bananas
    int maxNumBananas = -1;
    for (int i = 0; i < n; i++) {
        cin >> buckets[i];
        if (buckets[i] > maxNumBananas)
            maxNumBananas = buckets[i];
    }
    int m; // the numbe
    cin >> m;// r of super monkeys
    vi supermonkeys(m);
    for (int i = 0; i < m; i++)
        cin >> supermonkeys[i];

// loop over the buckets
    vii finalSol;
    vii memo(maxNumBananas + 1, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        //apply the recursive call on every bucket to get the minimum number fo buckets
        ii bucketInfo = solve(buckets[i], buckets[i], supermonkeys, memo);
        finalSol.push_back(make_pair(buckets[i] - bucketInfo.first, bucketInfo.second));

    }
    for (int i = 0; i < n; i++) {
        cout << finalSol[i].first << " " << finalSol[i].second << endl
    }


    return 0;
}