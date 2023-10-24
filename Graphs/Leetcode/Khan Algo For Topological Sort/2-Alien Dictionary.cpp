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
    string alienOrder(vector<string> &words)
    {
        if (words.size() == 0)
            return "";

        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegrees;
        string result = "";
        queue<char> zeroDegrees;

        for (string word : words)
        {
            for (char letter : word)
            {
                if (graph.find(letter) == graph.end())
                {
                    result += letter;
                    vector<char> v;
                    graph[letter] = v;
                    inDegrees[letter] = 0;
                }
            }
        }

        if (words.size() == 1)
            return result;
        result = "";

        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool found = false;
            int length = word1.size() <= word2.size() ? word1.size() : word2.size();
            for (int i = 0; i < length; i++)
            {
                char letter1 = word1[i];
                char letter2 = word2[i];
                if (letter1 != letter2)
                {
                    graph[letter1].push_back(letter2);
                    inDegrees[letter2]++;
                    found = true;
                    break;
                }
            }
            if (!found && word1.size() > word2.size())
                return "";
        }
        for (auto letter : inDegrees)
        {
            if (letter.second == 0)
                zeroDegrees.push(letter.first);
        }

        while (!zeroDegrees.empty())
        {
            char currentChar = zeroDegrees.front();
            zeroDegrees.pop();
            result += currentChar;
            for (char child : graph[currentChar])
            {
                inDegrees[child]--;
                if (inDegrees[child] == 0)
                    zeroDegrees.push(child);
            }
        }
        if (result.size() != graph.size())
            return "";
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