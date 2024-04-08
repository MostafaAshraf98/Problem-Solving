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
    int count = 0;
    bool solve(const string &s, int start, int end)
    {
        if (start < 0 || end == s.size() || s[start] != s[end])
            return false;

        if (s[start] == s[end])
            count++;

        solve(s, start - 1, end + 1);
        if (start - 1 >= 0 && start == end && s[start - 1] == s[start])
        {
            count++;
            solve(s, start - 2, end + 1);
        }
        if (start == end)
            solve(s, end + 1, end + 1);
        return true;
    }
    int countSubstrings(string s)
    {
        solve(s, 0, 0);
        return count;
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