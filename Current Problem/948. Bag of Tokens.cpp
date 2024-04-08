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
    static bool cmp(const int &t1, const int &t2)
    {
        return t1 >= t2;
    }
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end(), cmp);
        int score = 0;
        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 <= ptr2)
        {
            if (power >= tokens[ptr2])
            {
                score++;
                power -= tokens[ptr2];
                ptr2--;
                continue;
            }
            else if (score >= 1 && ptr1 != ptr2)
            {
                score--;
                power += tokens[ptr1];
                ptr1++;
                continue;
            }
            break;
        }
        return score;
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