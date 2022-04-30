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

//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int swaps = 0;
        int numberOfOpened = 0;
        stack<int> indicesOfOpen;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '[')
                indicesOfOpen.push(i);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[')
                numberOfOpened++;
            else {
                if (numberOfOpened > 0) // if there is a bracket already open, this will be its closing bracket
                    numberOfOpened--;
                else // there is no open bracket
                {
                    //we will apply swaping with last opening bracket
                    swaps++;
                    numberOfOpened++;
                    int swapWithIndex = indicesOfOpen.top();
                    indicesOfOpen.pop();
                    s[i] = '[';
                    s[swapWithIndex] = ']';
                }

            }
        }
        return swaps;
    }
};

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    string s = "[]";
    Solution sol;
    cout<< sol.minSwaps(s) << endl;
    return 0;
}