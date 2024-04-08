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
// String manipulation
// Three conditions must be satisfied: 
// 1. the 2 strings must be of the same size
// 2. the 2 strings must contain the same letters
// 3. the 2 strings must contain the same counts of occurences letters, for example 3 times 2 occurences 1 time 1 occurence and so on.

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char letter : word1)
            if (mp1.find(letter) == mp1.end())
                mp1[letter] = 1;
            else
                mp1[letter]++;

        for (char letter : word2)
            if (mp1.find(letter) == mp1.end())
                return false;
            else if (mp2.find(letter) == mp2.end())
                mp2[letter] = 1;
            else
                mp2[letter]++;

        for (char letter : word1)
            if (mp2.find(letter) == mp2.end())
                return false;

        unordered_map<int, int> count1;
        unordered_map<int, int> count2;

        for (auto it : mp1)
        {
            if (count1.find(it.second) == count1.end())
                count1[it.second] = 1;
            else
                count1[it.second]++;
        }

        for (auto it : mp2)
        {
            if (count2.find(it.second) == count2.end())
                count2[it.second] = 1;
            else
                count2[it.second]++;
        }

        for (auto it : count1)
        {
            if (count2.find(it.first) == count2.end())
                return false;
            if (count2[it.first] != count1[it.first])
                return false;
        }
        return true;
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