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

// Accepted
// Strings and maps

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> lettersCount;
        unordered_map<int, int> countFreq;
        int result = 0;
        for (char letter : s)
        {
            if (lettersCount.find(letter) == lettersCount.end())
                lettersCount[letter] = 1;
            else
                lettersCount[letter]++;
        }

        for (auto it : lettersCount)
        {
            if (countFreq.find(it.second) == countFreq.end())
                countFreq[it.second] = 1;
            else
                countFreq[it.second]++;
        }

        for (auto it : countFreq)
        {
            int temp = it.first - 1;
            while (it.second > 1)
            {
                if (temp == 0)
                {
                    result += it.first * (it.second - 1);
                    it.second = 1;
                }
                else if (countFreq.find(temp) == countFreq.end())
                {
                    it.second--;
                    result += it.first - temp;
                    countFreq[temp] = 1;
                }
                temp--;
            }
        }
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