#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e2;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3302
//ACCEPTED


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    while (scanf("%d", &n) && n != 0) {
        bool ans = 1;
        vii cars;
        for (int i = 0; i < n; i++) {
            ii x;
            scanf("%d %d", &x.first,&x.second);
            cars.push_back(x);
        }
        vi arr;
        for(int i=0;i<n;i++)
            arr.push_back(-1);
        for (int i = 0; i < n; i++) { // Position in race is 0 indexed
            int posWonLost = cars[i].second;
            int initialPos = posWonLost + i;
            if (initialPos < 0 || initialPos>=n||arr[initialPos] != -1 ) {
                ans = 0;
                break;
            }
            arr[initialPos] = cars[i].first;
        }
        if(ans)
        {
            for(int i=0;i<n;i++)
            {
                printf("%d",arr[i]);
                if(i!=n-1)
                    printf(" ");
            }
        } else
            printf("-1");
        printf("\n");
    }
    return 0;
}