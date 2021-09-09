#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2949
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    ll N, M, x;
    while (cin >> N >> M && (M != 0 && N != 0)) {
        vector<ll> Jack;
        vector<ll> Jill;
        int Count = 0;
        for (int i = 0; i < N; i++) {
            cin >> x;
            Jack.push_back(x);
        }
        for (int i = 0; i < M; i++) {
            cin >> x;
            Jill.push_back(x);
        }
        int i(0),j(0);
        while(i!=N && j!=M)
        {
            if(Jack[i]>Jill[j])
            j++;
            else if (Jill[j]>Jack[i])
                i++;
            else
            {
                Count++;
                i++;
                j++;
            }
        }
        cout << Count << endl;
    }
    return 0;
}