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

// Greedy
// Accepted

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int countARemovals = 0;
        int countBRemovals = 0;
        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] == 'A' && colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
                countARemovals++;

            if (colors[i] == 'B' && colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
                countBRemovals++;
        }
        if (countARemovals > countBRemovals)
            return true;
        return false;
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