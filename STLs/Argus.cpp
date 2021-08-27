#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3644
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string str;
    map<int,int> l;
    int min=INF;
    while(cin>>str && str=="Register")
    {
        int x,y;
        cin>>x>>y;
        l[x]=y;
        if(min > y)
            min=y;
    }
    int k;
    cin>>k;
    int time=min;
        while(k)
        {
            for(auto v:l)
            {
                if(k==0)
                    break;
                if(time%v.second ==0)
                {
                    cout << v.first <<endl;
                    k--;
                }
            }
            time++;
        }
    return 0;
}