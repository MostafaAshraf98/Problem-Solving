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
    int numMatchingSubseq(string s, vector<string> &words) {
        int answer = 0;

        // We have a vector of vectors
        // the row represents the char that all the elements in the cols start with
        vector<vector<string>> heads;
        for (int i = 0; i < 26; i++) {
            vector<string> v;
            heads.push_back(v);
        }

        // Add all the words starting with the correspongding letter to this vector of heads (They are the remaining letters that iam seaching for in each word)
        for (string word: words) {
            int firstCharIndex = word[0] - 'a';
            heads[firstCharIndex].push_back(word);
        }

        //Loop over all the letters in the string
        for (char letter: s) {
            vector<string> oldBucket = heads[letter -
                                             'a']; // This is the vector corresponding to words starting with this letter
            heads[letter - 'a'].clear();
            for (int i = 0; i < oldBucket.size(); i++) {
                string newWord = oldBucket[i].erase(0, 1);
                if (newWord.size() == 0) {
                    answer++;
                } else {
                    heads[newWord[0] - 'a'].push_back(newWord);
                }
            }
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