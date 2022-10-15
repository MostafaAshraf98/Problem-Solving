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
    bool reorderedPowerOf2(int n) {
        string number = to_string(n);
        sort(number.begin(),number.end());
        bool found = false;
        do {
            if (number[0] == '0')
                continue;
            double intNumber = stoi(number);
            double result = log2(intNumber);
            if (result == (int) result) {
                found = true;
                break;
            }

        } while (next_permutation(number.begin(), number.end()));
        return found;
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    Solution* sol= new Solution();
    sol->reorderedPowerOf2(521);
    return 0;
}