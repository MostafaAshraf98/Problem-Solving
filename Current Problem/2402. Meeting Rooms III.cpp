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
// Min Heap and sorting and greedy.

class Solution
{
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] == v2[0])
            return v1[1] <= v2[1];
        return v1[0] <= v2[0];
    }

    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), cmp);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> busyRooms;
        vector<long long> count(n, 0);
        set<int> emptyRooms;

        for (int i = 0; i < n; i++)
            emptyRooms.insert(i);

        for (int i = 0; i < meetings.size(); i++)
        {
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            while (!busyRooms.empty() && busyRooms.top().first <= start)
            {
                emptyRooms.insert(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!emptyRooms.empty())
            {
                int currentEmptyRoom = *emptyRooms.begin();
                emptyRooms.erase(emptyRooms.begin());
                busyRooms.push({end, currentEmptyRoom});
                count[currentEmptyRoom]++;
            }
            else
            {
                long long nextEmptyRoom = busyRooms.top().second;
                long long emptyTime = busyRooms.top().first;
                busyRooms.pop();
                busyRooms.push({emptyTime + end - start, nextEmptyRoom});
                count[nextEmptyRoom]++;
            }
        }

        long long maxValue = -1;
        long long maxRoomIndex;
        for (int i = 0; i < n; i++)
            if (count[i] > maxValue)
            {
                maxValue = count[i];
                maxRoomIndex = i;
            }
        return maxRoomIndex;
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