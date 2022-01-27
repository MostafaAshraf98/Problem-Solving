#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, OO = 2e9, MOD = 1e9 + 7, EPS = 1e-9;

int A[] = {5, 3, 7, 8, 11, 4, 5, 6, 7, 8, 1, 11 , 50000};
int n = 12;
int mem[50];
int LIS(int prv) {
    if (prv == -1)
        return 0;
    int& ret= mem[prv];
    if(~ret) return ret;
    ret = 1;
    for (int i = 0; i < prv; ++i){
        if(A[i]<A[prv])
            ret=max(ret,LIS(i)+1);
    }
    return ret;
}
int memo[20][21];
int solve(int pos , int lst){
    if(pos == n)
        return 0;
    if(lst!=-1&&memo[pos][lst]!=-1) return memo[pos][lst];
    int pick  = (lst==-1||A[pos]>A[lst])? solve(pos+1,pos) +1 : 0;
    int leave = solve(pos+1,lst);
    if(lst!=-1)
        memo[pos][lst] = max(pick,leave);
    return max(pick,leave);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    memset(memo,-1,sizeof memo);
    cout << solve(0,-1);
    return 0;
}