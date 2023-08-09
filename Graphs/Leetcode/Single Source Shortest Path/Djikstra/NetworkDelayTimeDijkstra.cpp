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
    void dijkstra(const vector<vector<pair<int, int>>> &adj, vector<int> &cost, int source, int n)
    {
        // pair<int, int>: This indicates the type of elements stored in the priority queue.
        // In this case, each element is a pair of two integers.

        // vector<pair<int, int>>: This specifies the underlying container that the priority_queue will use to store
        // the elements. In this case, a vector is used to store pairs of integers.

        // greater<pair<int, int>>: This specifies the comparison function that defines the priority order of elements
        // in the priority queue. The greater function object is used here, which results in a min-heap behavior.
        // It means that the element with the smallest value of the first integer in the pair will have the highest
        // priority in the queue. This is opposite to the default behavior, which uses the less function object and results in a max-heap 
        // (largest element has the highest priority).

        // The priority queue stores pairs, the first element in the pair is the cost to reach this node and the second is the node index.

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, source});

        // Time for starting node is 0
        cost[source] = 0;

        while (!pq.empty())
        {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // if the cost to reach this node in the PQ is greater than the stored cost we neglect this element in the queue
            // this means that i already visited this node and assigned a lower cost to it.
            if (currNodeTime > cost[currNode])
            {
                continue;
            }

            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode])
            {
                int time = edge.first;
                int neighborNode = edge.second;

                // Fastest signal time for neighborNode so far
                // signalReceivedAt[currNode] + time :
                // time when signal reaches neighborNode
                if (cost[neighborNode] > currNodeTime + time)
                {
                    cost[neighborNode] = currNodeTime + time;
                    pq.push({cost[neighborNode], neighborNode});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (vector<int> time : times)
        {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];

            adj[source].push_back({travelTime, dest});
        }

        vector<int> cost(n + 1, INT_MAX);
        dijkstra(adj, cost, k, n);

        int answer = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            answer = max(answer, cost[i]);
        }

        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
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