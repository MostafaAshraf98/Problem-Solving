#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    ll s; // the total size to reach
    ll a; // the size of the ball a
    ll b; // the size of the ball b
    cin>> s >> a >>b;
    ll countBallsA=0;
    ll countBallsB=0;
    ll rem = s%b; // remainder of the division of s by b
    ll div = s/b;
    if(rem%a==0)
    {
        cout << rem/a <<" "<< s/b << " 0" <<endl;
        return 0;
    }
    ll bestRem=rem%a;
    ll bestB=div;
    ll bestA=rem/a;

    ll currentRemBalls = rem%a;
    ll currentBBalls=div;
    ll currentABalls = rem/a;
    while(currentBBalls!=0)
    {
        currentBBalls--;
        currentRemBalls+=b;
        currentABalls+=currentRemBalls/a;
        currentRemBalls= currentRemBalls%a;
        if(currentRemBalls==0)
        {
            bestRem=currentRemBalls;
            bestB=currentBBalls;
            bestA=currentABalls;
            break;
        }
        if(currentRemBalls<bestRem)
        {
            bestRem=currentRemBalls;
            bestB=currentBBalls;
            bestA=currentABalls;
        }

    }
    cout << bestA << " " << bestB << " " << bestRem<<endl;

    return 0;
}