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
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        unordered_map<char, int> mp;
        string newString = "";
        int count = 0;
        for (char letter: pattern) {
            auto it = mp.find(letter);
            if (mp.find(letter) == mp.end()) {
                mp[letter] = count;
                newString += to_string(count);
                count++;
            } else {
                newString += to_string(it->second);
            }
        }
        pattern = newString;

        vector<string> answer;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int count = 0;
            unordered_map<char, int> mp; // it maps every character to a nubmer
            string newString = "";
            for (char letter: word) {
                auto it = mp.find(letter);
                if (mp.find(letter) == mp.end()) {
                    mp[letter] = count;
                    newString += to_string(count);
                    count++;
                } else {
                    newString += to_string(it->second);
                }
            }
            if (newString == pattern)
                answer.push_back(word);
        }
        return answer;
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