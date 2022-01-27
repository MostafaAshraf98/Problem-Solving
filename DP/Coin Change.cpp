#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, OO = 2e9, MOD = 1e9 + 7, EPS = 1e-9;
int coins[] = {50,25,10,5,1};
int n = 5;
ll mem[7490][5];
ll solve(int flos , int coin){
    if(flos==0) return 1;
    if(coin == n)
        return 0;
    ll& ret = mem[flos][coin];
    if(~ret) return ret;
    int pick = (flos>=coins[coin])? solve(flos-coins[coin],coin) : 0;
    int leave = solve(flos,coin +1 );
    return ret = leave + pick;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int x;
        memset(mem,-1ll,sizeof mem);
    while(cin>>x){
        cout<<solve(x,0)<<endl;
    }
    return 0;
}