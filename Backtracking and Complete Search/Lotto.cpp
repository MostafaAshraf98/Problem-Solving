#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
int n = 6;
int k;
int arr[50];
int taken[50];
vi v;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382
//ACCEPTED

void solve(int pos,int count)//pos is for the array and count is the number of taken elements
{
    if(pos==k)
    {
        if(count!=n)
            return;
        for( int i=0;i<v.size();i++)
        {
            cout << v[i];
            if(i!=v.size()-1)
                cout << " ";
        }
        cout << endl;
        return;;
    }
 //pick
 v.push_back(arr[pos]);
    solve(pos+1,count+1);
    v.pop_back();

    //leave
    solve(pos+1,count);


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    bool first=true;
    while (cin >> k && k != 0) {
        if(first)
            first = false;
        else
            cout << endl;

        v.clear();
        memset(taken,0,50);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        solve(0,0);
    }

    return 0;
}