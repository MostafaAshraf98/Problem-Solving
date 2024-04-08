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

class UnionFind
{
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int size) : root(size), rank(size)
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
    void reset(int x)
    {
        root[x] = x;
        rank[x] = 1;
    }
};

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto meeting : meetings)
        {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];
            if (sameTimeMeetings.find(time) == sameTimeMeetings.end())
            {
                vector<pair<int, int>> v;
                v.push_back({p1, p2});
                sameTimeMeetings[time] = v;
            }
            else
            {
                sameTimeMeetings[time].push_back({p1, p2});
            }
        }
        UnionFind uf(n);
        uf.unionSet(0, firstPerson);

        for (auto time : sameTimeMeetings)
        {
            vector<pair<int, int>> currentMeetings = time.second;
            for (auto meeting : currentMeetings)
                uf.unionSet(meeting.first, meeting.second);

            for (auto meeting : currentMeetings)
            {
                if (!uf.isConnected(meeting.first, 0))
                    uf.reset(meeting.first);
                if (!uf.isConnected(meeting.second, 0))
                    uf.reset(meeting.second);
            }
        }
        vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            if (uf.isConnected(i, 0))
                answer.push_back(i);
        }
        return answer;
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