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

// 00000011111111
class Solution
{

public:
    bool valid(vector<int> &dist, const int &speed, const double &hour)
    {
        double totalTimeTaken = 0;

        for (int i = 0; i < dist.size() - 1; i++)
            totalTimeTaken += ceil(dist[i] / (float)speed);

        totalTimeTaken += dist[dist.size() - 1] / (double)speed;

        return totalTimeTaken <= hour;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (dist.size() == 0)
            return 0;

        if (dist.size() == 1)
        {
            double result = dist[0] / hour;
            result = round(result * 100) / 100.0;
            return ceil(result);
        }

        if (hour <= dist.size() - 1)
            return -1;

        int start = 0;
        int end = 10E7 + 1;

        while (start != end)
        {
            int mid = start + (end - start) / 2;
            if (valid(dist, mid, hour))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
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