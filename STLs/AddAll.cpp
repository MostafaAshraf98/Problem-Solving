#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
int n;
while(cin>>n && n!=0)
{
    multiset<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.insert(x);
    }
    if(v.size()==1 || v.size()==0)
    {
        cout << "0" << endl;
        continue;
    }
    auto it = v.begin();
    int cost = 0;
    int prev;
    while(v.size()!=1)
    {
        prev=*it + *(++it);
        cost+=prev;
        v.erase(v.begin());
        v.erase(v.begin()++);
        v.insert(prev);
        it=v.begin();
    }
    cout << cost << endl;
}
    return 0;
}