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
// 0000011111111
// 0 --> means it is increasing
// 1 --> means it is decreasing

class Solution
{
public:
    int BS(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid + 1])
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }

    int peakIndexInMountainArray(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;

        if (arr[0] > arr[1])
            return 0;

        if (arr[arr.size() - 1] > arr[arr.size() - 2])
            return arr.size() - 1;

        return BS(arr);
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