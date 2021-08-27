#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2619
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
int t;
cin >> t;
while(t--)
{
    int n;
    cin >>n;
    int longest=0;
    vector<ll> currentSeq;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        auto it = find(currentSeq.begin(),currentSeq.end(),x);
        if(currentSeq.empty() || it==currentSeq.end())
        {
            currentSeq.push_back(x);
        }
        else
        {
            if(currentSeq.size()>longest)
                longest=currentSeq.size();
            currentSeq.erase(currentSeq.begin(),++it);
            currentSeq.push_back(x);
        }
    }
    if(currentSeq.size()>longest)
        longest=currentSeq.size();
    cout << longest << endl;
}
    return 0;
}