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
    int getWinner(vector<int> &arr, int k)
    {
        deque<int> q;
        int maxVal = -1;
        int maxValIndex = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            int num = arr[i];
            q.push_back(num);
            if (num > maxVal)
            {
                maxVal = num;
                maxValIndex = i;
            }
        }
        if (maxValIndex <= k)
            return maxVal;

        int lastWinner = -1;
        int count = 0;
        while (true)
        {
            int integer1 = q.front();
            q.pop_front();
            int integer2 = q.front();
            q.pop_front();

            int winningInteger = integer1 > integer2 ? integer1 : integer2;
            int losingInteger = winningInteger == integer1 ? integer2 : integer1;

            if (winningInteger == lastWinner)
                count++;
            else
            {
                lastWinner = winningInteger;
                count = 1;
            }
            if (count == k)
                return winningInteger;
                
            q.push_front(winningInteger);
            q.push_back(losingInteger);
        }
        return -1;
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