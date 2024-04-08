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

// Accepted

struct CountMaterial
{
    int glass = 0;
    int paper = 0;
    int metal = 0;
};

class Solution
{
public:
    CountMaterial countLetterInString(const string &s)
    {
        CountMaterial count;
        for (char ch : s)
            if (ch == 'M')
                count.metal++;
            else if (ch == 'G')
                count.glass++;
            else
                count.paper++;
        return count;
    }
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int n = garbage.size();
        vector<int> cumulativeTravel(n, 0);

        CountMaterial initial = countLetterInString(garbage[0]);
        int result = initial.glass + initial.paper + initial.metal;

        int glassTruck = 0;
        int paperTruck = 0;
        int metalTruck = 0;
        
        for (int i = 1; i < n; i++)
        {
            cumulativeTravel[i] = travel[i - 1] + cumulativeTravel[i - 1];
            CountMaterial count = countLetterInString(garbage[i]);

            if (count.glass > 0)
            {
                result += count.glass + cumulativeTravel[i] - cumulativeTravel[glassTruck];
                glassTruck = i;
            }
            if (count.metal > 0)
            {
                result += count.metal + cumulativeTravel[i] - cumulativeTravel[metalTruck];
                metalTruck = i;
            }
            if (count.paper > 0)
            {
                result += count.paper + cumulativeTravel[i] - cumulativeTravel[paperTruck];
                paperTruck = i;
            }
        }
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