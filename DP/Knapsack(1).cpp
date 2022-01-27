#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, OO = 2e9, MOD = 1e9 + 7, EPS = 1e-9;
int W[N];
int P[N];
int n, maxW;
int mem[2000][2001];
int solve(int pos, int wight) {
    if(wight<0) return -1e9;
    if (pos == n)
        return 0;
    int& ret = mem[pos][wight];
    if(~ret) return ret;
    int pick =  solve(pos + 1, wight - W[pos])  + P[pos];
    int leave = solve(pos + 1, wight);
    return ret = max(pick, leave);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    memset(mem,-1,sizeof mem);
    scanf("%d%d", &maxW, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d",W+i, P+i);

    printf("%d\n",solve(0,maxW));
    return 0;
}