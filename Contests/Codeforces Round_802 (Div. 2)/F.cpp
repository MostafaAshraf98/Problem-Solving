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


int solve(const vector<ii> &indicesZeros, const vector<ii> &indicesOnes, map<pair<int, string>, int> &mp, int index,
          string taken) {
    if (index == indicesZeros.size())
        return 0;
    if (mp.find(make_pair(index, taken)) != mp.end())
        return mp[make_pair(index, taken)];

    int min = INT_MAX;
    int count = 0;

    //Loop over the ones
    for (int i = 0; i < indicesOnes.size(); i++) {

        if (taken[i] == '1')
            continue;
        if (count == 3)
            break;
        ii one = indicesOnes[i];
        int dist = abs(indicesZeros[index].first - one.first) + abs(indicesZeros[index].second - one.second);
        if (dist >= min) // pruning
            continue;
        //do
        taken[i] = '1';
        count++;
        //recurse
        dist += solve(indicesZeros, indicesOnes, mp, index + 1, taken);
        if (dist < min)
            min = dist;
        //undo
        taken[i] = '0';
    }
    return mp[make_pair(index, taken)] = min;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> currentConfig(2, vector<int>(n));
    int temp;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) {
            cin >> currentConfig[i][j];
        }
    vector<ii> indicesZeros;
    vector<ii> indicesOnes;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) {
            cin >> temp;
            {
                if (temp != currentConfig[i][j]) {
                    if (currentConfig[i][j] == 0)
                        indicesZeros.push_back(make_pair(i, j));
                    else
                        indicesOnes.push_back(make_pair(i, j));
                }
            }
        }
    if (indicesZeros.size() != indicesOnes.size()) {
        cout << -1 << endl;
        return 0;
    }

    string taken(indicesOnes.size(), '0');
    map<pair<int, string>, int> mp;
    cout << solve(indicesZeros, indicesOnes, mp, 0, taken) << endl;
    return 0;
}