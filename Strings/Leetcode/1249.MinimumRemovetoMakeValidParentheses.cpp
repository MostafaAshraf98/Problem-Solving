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
    string minRemoveToMakeValid(string s) {
        string result = "";
        int countCurrOpen = 0;
        int countCouple = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                countCurrOpen++;
            else if (s[i] == ')') {
                if (countCurrOpen == 0)
                    continue;
                countCurrOpen--;
                countCouple++;
            }
            result += s[i];
        }
        if (countCurrOpen == 0)
            return result;

        string result2 = "";
        for (int i = 0; i < result.size(); i++) {
            if (countCouple == 0 && result[i] == '(')
                continue;
            else if (result[i] == '(')
                countCouple--;
            result2 += result[i];
        }
        return result2;
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