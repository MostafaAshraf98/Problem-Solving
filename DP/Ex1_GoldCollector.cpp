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

ll getMax(ll x,ll y)
{
    if(x>y)
        return x;
    else
        return y;
}

ll solve(vector<vector<ll>> &v, vector<vector<ll>> &memo, int currentRow, int currentCol, const int &N, const int &M) {
//    if (currentRow >= N || currentCol >= M) // if we are out of bounds of the area (2D matrix)
//        return -INF;
    if (currentRow == N - 1 && currentCol == M - 1) // arrived to the final cell
    {
        return v[currentRow][currentCol];
    }

    //transitions
    if (memo[currentRow][currentCol] != -1)
        return memo[currentRow][currentCol];

    //move down
    ll down;
    if (currentRow + 1 >= N) // invalid
        down =  LLONG_MIN;
    else
        down = v[currentRow][currentCol] + solve(v, memo, currentRow + 1, currentCol, N, M);

    //move right
    ll right;
    if (currentCol + 1 >= M) // invalid
        right = LLONG_MIN;
    else
        right = v[currentRow][currentCol] + solve(v, memo, currentRow, currentCol + 1, N, M);

    //move down right
    ll downright;
    if (currentRow + 1 >= N || currentCol + 1 >= M) // invalid
        downright = LLONG_MIN;
    else
        downright = v[currentRow][currentCol] + solve(v, memo, currentRow + 1, currentCol + 1, N, M);

    ll maximum = getMax(down, right);
    maximum = getMax(maximum, downright);
    return memo[currentRow][currentCol] = maximum;

}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int N, M; // the dimensions of the grid
    cin>> N >>M;
    vector<vector<ll>> v(N, vector<ll>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin>>v[i][j];

    vector<vector<ll>> memo(N, vector<ll>(M, -1));
    ll sol = solve(v, memo, 0, 0, N, M);
    cout << sol <<endl;
    return 0;
}