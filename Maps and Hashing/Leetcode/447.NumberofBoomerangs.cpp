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


class Solution {
public:

    long long findFact(int n, vector<long long> &memo) {
        if (n == 1 || n == 0)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        return memo[n] = n * findFact(n - 1, memo);
    }

    int numberOfBoomerangs(vector<vector<int>> &points) {
        vector<long long> memo(501, -1);
        int count = 0;
        for (auto point: points) {
            unordered_map<double, int> mp;
            for (auto secondPoint: points) {
                double distance = sqrt(pow(point[0] - secondPoint[0], 2) + pow(point[1] - secondPoint[1], 2));
                if (mp.find(distance) == mp.end())
                    mp[distance] = 1;
                else
                    mp[distance]++;
            }
            for (auto it = mp.begin(); it != mp.end(); it++) {
                int n = it->second;
                if (n > 1)
                    count += findFact(n, memo) / findFact(n - 2, memo);
            }
        }
        return count;
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