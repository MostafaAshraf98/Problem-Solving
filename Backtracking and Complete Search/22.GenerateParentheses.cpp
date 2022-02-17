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

//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:

    void
    solve(int n, int countCurrentOpen, int formedPairs, string currentString, vector<string> &solution) {
        if (formedPairs == n) {
            solution.push_back(currentString);
            return;
        }

        if (countCurrentOpen + formedPairs != n) // then we can open
            solve(n, countCurrentOpen + 1, formedPairs, currentString + "(", solution);
        if (countCurrentOpen > 0)// then we can close
            solve(n, countCurrentOpen - 1, formedPairs + 1, currentString + ")", solution);

    }

    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        solve(n, 1, 0, "(", solution);
        return solution;
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