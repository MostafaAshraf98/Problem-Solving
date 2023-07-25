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

// for example if x=2 and n =3,
// first call x=2 and n=3, => ans =2*2*2
// second call x=2 and n=1 => ans =1*1*2 =2 => returns 2
// third call x=2, and n=0 => returns 1
// the idea is that the if condition bet3awad the flooring eli beye7sal lama ba3mel n/2

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1; // base case , ay 7aga exp 0 betedi 1
            
        long long num = n;
        bool isNegative = n < 0;

        if (isNegative)
            num *= -1;

        double ans = myPow(x, num / 2);
        ans *= ans;  // ba3melaha square

        if (num % 2) // el exp odd
            ans *= x;

        if (isNegative)
            return 1 / ans;
        return ans;
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