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
    int n;
    int index;
    int maxSum;

    bool valid(int value)
    {
        long count = 0;

        // On index's left:
        // If value > index, there are index + 1 numbers in the arithmetic sequence:
        // [value - index, ..., value - 1, value].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [1, 2, ..., value - 1, value], plus a sequence of length (index - value + 1) of 1s.
        if (value > index)
        {
            count += (long)(value + value - index) * (index + 1) / 2;
        }
        else
        {
            count += (long)(value + 1) * value / 2 + index - value + 1;
        };
        // On index's right:
        // If value >= n - index, there are n - index numbers in the arithmetic sequence:
        // [value, value - 1, ..., value - n + 1 + index].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [value, value - 1, ..., 1], plus a sequence of length (n - index - value) of 1s.
        if (value >= n - index)
        {
            count += (long)(value + value - n + 1 + index) * (n - index) / 2;
        }
        else
        {
            count += (long)(value + 1) * value / 2 + n - index - value;
        }

        return count - value <= maxSum;
    }
    int BS()
    {
        long long start = 0;
        long long end = maxSum;
        while (start < end)
        {
            long long mid = start + (end - start + 1) / 2;
            if (valid(mid))
                start = mid;
            else
                end = mid - 1;
        }
        return start;
    }

    int maxValue(int n, int index, int maxSum)
    {
        this->n = n;
        this->index = index;
        this->maxSum = maxSum;
        return BS();
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