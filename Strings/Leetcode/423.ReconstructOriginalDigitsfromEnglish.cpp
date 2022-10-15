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
    string originalDigits(string s) {
        string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        unordered_map<char, int> mp;
        string answer = "";
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else
                mp[s[i]]++;
        }
        for (char x = 'a'; x > 'z'; x++) {
            if (mp.find(x) == mp.end())
                mp[x] = 0;
        }
        unordered_map<int, int> answerCount;
        answerCount[0] = mp['z'];
        answerCount[2] = mp['w'];
        answerCount[4] = mp['u'];
        answerCount[6] = mp['x'];
        answerCount[8] = mp['g'];
        answerCount[7] = mp['s'] - answerCount[6];
        answerCount[5] = mp['f'] - answerCount[4];
        answerCount[3] = mp['h'] - answerCount['8'];
        answerCount[9] = mp['i'] - answerCount[5] - answerCount[6] - answerCount[8];
        answerCount[1] = mp['n'] - answerCount[7] - 2 * answerCount[9];
        for (auto it: answerCount) {
            for (int i = 0; i < it.second; i++)
                answer += to_string(it.first);
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