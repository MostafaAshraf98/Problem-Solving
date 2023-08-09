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
    string s1;
    string s2;
    vector<vector<int>> memo;

    int solve(int ptr1, int ptr2)
    {
        if (ptr1 >= s1.size())
        {
            int sum = 0;
            while (ptr2 < s2.size())
            {
                sum += s2[ptr2];
                ptr2++;
            }
            return sum;
        }
        if (ptr2 >= s2.size())
        {
            int sum = 0;
            while (ptr1 < s1.size())
            {
                sum += s1[ptr1];
                ptr1++;
            }
            return sum;
        }
        if (memo[ptr1][ptr2] != -1)
            return memo[ptr1][ptr2];
        // move ptr1
        int moveBoth = INT_MAX;
        if (s1[ptr1] == s2[ptr2])
            moveBoth = solve(ptr1 + 1, ptr2 + 1);

        int movePtr1 = s1[ptr1] + solve(ptr1 + 1, ptr2);
        int movePtr2 = s2[ptr2] + solve(ptr1, ptr2 + 1);

        return memo[ptr1][ptr2] = min(moveBoth, min(movePtr1, movePtr2));
    }

    int minimumDeleteSum(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;
        memo = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
        return solve(0, 0);
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