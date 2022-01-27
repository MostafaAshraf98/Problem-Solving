#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2950
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
int n;
while(scanf("%d",&n) && n!=0)
{
    int stations[N];
    int ans=true;
    for(int i=0;i<n;i++)
        scanf("%d",&stations[i]);
    sort(stations,stations+n);
    if(stations[0]>200 || stations[n-1]<1322) // 3alashan hatrou7 w terga3 fa el masafa mabein a5er station wel end must be lessa than or equal 200
        ans= false;
    stations[n]=1422;
    for(int i=0;i<n;i++)
    {
        if(!ans)
            break;
        if(stations[i+1]-stations[i]>200)
        {
            ans= false;
            break;
        }
    }
    if(!ans)
        printf("IMPOSSIBLE\n");
    else
        printf("POSSIBLE\n");

}
    return 0;
}