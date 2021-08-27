#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1301


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t, d, n, maxSum,max_x,max_y;
    cin >> t;
    while (t--) {
        maxSum = 0;
        int * arr[1025];
        for (int i = 0; i < 1025; i++) {
            arr[i] = new int[1025];
            for (int j = 0; j < 1025; j++)
                arr[i][j] = 0;
        }
        cin >> d; // strength of the gas bomb
        cin >> n; // number os rat populations
        for (int i = 0; i < n; i++) {
            int x, y, size;
            cin >> x >> y >> size;
            for(int k=x-d;k<=x+d;k++)
            {
                if(k<0 || k>1024)
                    continue;
                for(int g=y-d;g<=y+d;g++)
                {
                    if(g<0 || g>1024)
                        continue;
                    arr[k][g]+=size;
                }

            }
        }
        for(int i=0;i<1025;i++)
            for(int j=0;j<1025;j++)
            {
                if(arr[i][j]>maxSum)
                {
                    maxSum=arr[i][j];
                    max_x=i;
                    max_y=j;
                }
            }
            cout << max_x << " " << max_y << " " << maxSum << endl;
    }
    return 0;
}

// fekret el mas2ala eni 3andi array di fih kol el amaken eli fel grid eli momken a7ott fiha el bomb
// el values eli fel array di refers to the total size of rats that will be killed if we placed a bomb in this location
// ma3 kol rat population entered as input and using the value of d ( strength of bomb ) ba3mel add lel rat population di l kol el location within
// the range bema en ay location fihom haygebha .. fel a5er 5ales hayeb2a 3andi el values eli kol location hay-kill law placed el bomb fel makan da
// ba loop to get max