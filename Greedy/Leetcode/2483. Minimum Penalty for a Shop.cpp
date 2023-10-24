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
    int bestClosingTime(string customers)
    {
        vector<int> penality(customers.size() + 1, 0);
        int countN = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            penality[i] += countN;
            if (customers[i] == 'N')
                countN++;
        }
        penality[penality.size() - 1] = countN;
        int countY = 0;
        for (int i = customers.size() - 1; i >= 0; i--)
        {
            if (customers[i] == 'Y')
                countY++;
            penality[i] += countY;
        }
        int result = INT_MAX;
        int indexResult = -1;

        for (int i = 0; i < penality.size(); i++)
        {

            if (penality[i] < result)
            {
                result = penality[i];
                indexResult = i;
            }
        }

        return indexResult;
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