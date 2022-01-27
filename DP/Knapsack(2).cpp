#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
int n;
ll A[int(1e4+5)];
/*int solve(int pos, bool taken) {
    if (pos == n) return 0;
    ///opt 1 : pick
    int op1 = (taken) ? 0 : A[pos] + solve(pos + 1, 1);
    //opt2: leave
    int op2 = solve(pos + 1, 0);
    return max(op1, op2);
}
int frq[100];*/
ll memo[int(1e4+5)];
/*
 * 4
*1000      1          1       1000
 */
ll solve(int pos){
    if(pos >= n)
        return 0;
    if(memo[pos]!=-1) return memo[pos];
    return memo[pos] = max(solve(pos+1),A[pos] + solve(pos+2));
}
/*

ll fib(int n) {
    if (mem[n]) return mem[n];
    frq[n]++;
    if (n < 2) return mem[n] = 1;
    return mem[n] = fib(n - 1) + fib(n - 2);
}
 */
int tc;
int main() {

   
    cin>>tc;
    int cnt = 0;
    while(tc--) {
        memset(memo , -1ll , sizeof memo);
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        printf("Case %d: %lld\n",++cnt,solve(0));

    }
    return 0;
}