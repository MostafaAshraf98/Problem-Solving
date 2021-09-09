#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1846
//ACCEPTED
string arr[51];

bool comp(const int& a, const int &b)
// This function takes every 2 indices in arr of(string numbers) and
//returns true if appending arr[a] to arr[b] is greater than appending arr[b] to arr[a]
{
    string x=arr[a]+arr[b];
    string y =arr[b]+arr[a];
    for(int i=0;i<x.length();i++)
    {
        if(x[i]!=y[i])
            return x[i]>y[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
int H[51]; // array of indices;
int n;
while(cin>>n && n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        H[i]=i;
    }
    sort(H,H+n,comp); // here we sort the indices in order of greatest appended value
    for(int i=0;i<n;i++)
    {
        cout << arr[H[i]];
    }
    cout << endl;

}


    return 0;
}