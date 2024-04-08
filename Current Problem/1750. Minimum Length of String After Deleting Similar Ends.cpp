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
    int minimumLength(string s)
    {
        if (s.size() == 1)
            return 1;
        int ptr1 = 0;
        int ptr2 = s.size() - 1;
        while (ptr1 < ptr2)
        {
            if (s[ptr1] == s[ptr2])
            {
                ptr1++;
                ptr2--;
            }
            else if (ptr2 != s.size() - 1 && s[ptr1] == s[ptr2 + 1])
                ptr1++;
            else if (ptr1 != 0 && s[ptr2] == s[ptr1 - 1])
                ptr2--;
            else
                return ptr2 - ptr1 + 1;
        }
        if (ptr1 > ptr2)
            return 0;
        if (ptr1 == ptr2 && (ptr1 == 0 || (s[ptr1 - 1] == s[ptr1])) && ((ptr1 == s.size() - 1 || (s[ptr1 + 1] == s[ptr1]))))
            return 0;
        return 1;
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