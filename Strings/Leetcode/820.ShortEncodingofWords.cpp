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
    int minimumLengthEncoding(vector<string> &words) {
        std::sort(words.begin(), words.end(), []
                (const std::string& first, const std::string& second){
            return first.size() > second.size();
        });
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            int index = 0;
            bool found = false;
            while ((index = result.find(currentWord, index)) != std::string::npos) {
                if(result[index+currentWord.length()]=='#')
                {
                    found = true;
                    break;
                }
                std::cout << index << std::endl;
                index += currentWord.length();
            }
            if(!found)
                result+= currentWord + "#";
        }

        return result.size();
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