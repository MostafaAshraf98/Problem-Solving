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
    string intToRoman(int num) {
        map<int, string> mp = new map<int, string>();
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[400] = "CD";
        mp[900] = "CM";
        string answer = "";
        while (num != 0) {
            auto it = mp.end();
            it--;
            while (num - it->first < 0)
                it--;
            num -= it->first;
            answer += it->second;
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