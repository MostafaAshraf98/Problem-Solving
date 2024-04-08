#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)
#define sfs(s) scanf("%s", s)

#define pf(n) printf("%d", n)
#define pff(n, m) printf("%d %d", n, m)
#define pfl(n) printf("%I64d", n)
#define pffl(n, m) printf("%I64d %I64d", n, m)
#define pfs(s) printf("%s", s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int)10e4;

//Accepted

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        map<int, int> mp;
        for (int num : nums)
        {
            if (mp.find(num) == mp.end())
                mp[num] = 1;
            else
                mp[num]++;
        }
        auto it = mp.end();
        it--;
        int countElements = 0;
        int sum = 0;
        while (it != mp.begin())
        {
            countElements = countElements + it->second;
            sum += countElements;
            it--;
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}