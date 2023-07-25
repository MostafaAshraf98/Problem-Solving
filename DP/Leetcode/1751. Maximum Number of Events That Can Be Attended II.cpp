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
    multimap<int, pair<int, int>> ourEvents;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;

    int solve(int currentTime, multimap<int, pair<int, int>>::iterator it, int k, int currentIndex)
    {
        if (k == 0)
            return 0;

        if (it == ourEvents.end())
            return 0;

        auto temp1 = memo.find(currentIndex);
        if (temp1 != memo.end())
        {
            auto temp2 = temp1->second.find(currentTime);
            if (temp2 != temp1->second.end())
            {
                auto temp3 = temp2->second.find(k);
                if (temp3 != temp2->second.end())
                    return memo[currentIndex][currentTime][k];
            }
        }

        int start = it->first;
        int end = it->second.first;
        int value = it->second.second;

        int take = 0;
        int leave = 0;

        it++;
        if (start > currentTime)
            take = value + solve(end, it, k - 1, currentIndex + 1);

        leave = solve(currentTime, it, k, currentIndex + 1);

        return memo[currentIndex][currentTime][k] = max(take, leave);
    }

    bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] <= b[0];
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        for (vector<int> event : events)
        {
            int start = event[0];
            int end = event[1];
            int value = event[2];

            ourEvents.insert(make_pair(start, make_pair(end, value)));
        }
        return solve(0, ourEvents.begin(), k, 0);
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