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
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        string answer;

        for (char c : s)
        {
            if (mp.find(c) == mp.end())
                mp[c] = 1;
            else
                mp[c]++;
        }

        for (char c : order)
        {
            if (mp.find(c) != mp.end())
            {
                while (mp[c] > 0)
                {
                    answer.push_back(c);
                    mp[c]--;
                }
            }
        }
        
        for (auto it : mp)
        {
            int count = it.second;
            if (count > 0)
            {
                while (count > 0)
                {
                    answer.push_back(it.first);
                    count--;
                }
            }
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