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
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        unordered_map<char, int> finalMapWordB;
        for (string word2: words2) {
            unordered_map<char, int> mp2;
            for (char letter: word2) {
                if (mp2.find(letter) == mp2.end())
                    mp2[letter] = 1;
                else
                    mp2[letter]++;
            }
            for (auto it:mp2) {
                char c = it.first;
                char occ = it.second;
                auto it2 = finalMapWordB.find(c);
                if (it2 == finalMapWordB.end() || it2->second < occ)
                    finalMapWordB[c] = occ;
            }
        }

        vector<string> answer;
        for (string word1: words1) {
            unordered_map<char, int> mp1;
            for (char letter: word1) {
                if (mp1.find(letter) == mp1.end())
                    mp1[letter] = 1;
                else
                    mp1[letter]++;
            }
            bool valid = true;
            for (auto it: finalMapWordB) {
                char c = it.first;
                char occ = it.second;
                auto it1 = mp1.find(c);
                if (it1 == mp1.end() || it1->second < occ) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                answer.push_back(words1[i]);
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