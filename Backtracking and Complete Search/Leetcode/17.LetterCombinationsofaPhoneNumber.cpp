#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

class Solution {
public:
    unordered_map<char, vector<string>> mp;

    void solve(string &digits, int index, vector<string> &answer, string currentWord) {
        if (index == digits.size())
            answer.push_back(currentWord);

        auto possibleLetters = mp[digits[index]];
        for(int i=0;i<possibleLetters.size();i++)
        {
            // do
            currentWord+=possibleLetters[i];
            solve(digits,index+1,answer,currentWord);
            currentWord.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mp['2'] = vector<string> {"a", "b", "c"};
        mp['3'] = vector<string>{"d", "e", "f"};
        mp['4'] = vector<string>{"g", "h", "i"};
        mp['5'] = vector<string>{"j", "k", "l"};
        mp['6'] = vector<string>{"m", "n", "o"};
        mp['7'] = vector<string>{"p", "q", "r", "s"};
        mp['8'] = vector<string>{"t", "u", "v"};
        mp['9'] = vector<string>{"w", "x", "y", "z"};
        vector<string> answer;
        solve(digits, 0,answer, "");
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}