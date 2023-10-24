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

// Greedy
// Accepted

bool cmp(const string &s1, const string &s2)
{
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;
    for (int i = 0; i < s1s2.size(); i++)
    {
        if (s1s2[i] > s2s1[i])
            return true;
        else if (s1s2[i] < s2s1[i])
            return false;
    }
    return false;
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> vec;
        for (int num : nums)
            vec.push_back(to_string(num));

        sort(vec.begin(), vec.end(), cmp);
        string result;

        for (string num : vec)
            result += num;

        bool allZeros = true;
        for (char digit : result)
        {
            if (digit != '0')
                allZeros = false;
            break;
        }
        if (allZeros)
            return "0";
        return result;
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