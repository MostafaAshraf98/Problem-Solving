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

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        sort(batteries.begin(), batteries.end());
        long long extra = 0;
        vector<int> live;
        for (int i = 0; i < batteries.size(); i++)
        {
            if (i >= batteries.size() - n)
                live.push_back(batteries[i]);
            else
                extra += batteries[i];
        }
        long long result = live[0];
        for (int i = 0; i < live.size() - 1; i++)
        {
            int target = live[i + 1];
            long long required = (target - live[i]) * (i + 1);

            if (extra >= required)
            {
                extra -= required;
                result = target;
            }
            else
            {
                return live[i] + extra / (i + 1);
            }
        }
        result = result + (extra / n);
        return result;
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