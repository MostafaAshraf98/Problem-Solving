#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565
//ACCEPTED

int n;
int p;
int arr[20];
vi path;

int best;
vi pathMax;


void solve(int pos , int sum)
{
    if(pos==p || sum==n)
    {

        if(sum>best && sum<=n)
        {
            best=sum;
            pathMax.erase(pathMax.begin(),pathMax.end());
            for(int i=0;i<path.size();i++)
                pathMax.push_back(path[i]);
        }
        return;
    }
    if(sum>n)
        return;
    //pick;
    sum+=arr[pos];
    path.push_back(arr[pos]);
    solve(pos+1,sum);
    sum-=arr[pos];
    path.pop_back();

    //leave
    solve(pos+1,sum);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
string line;
while(getline(cin,line) && !line.empty())
{
    stringstream ss(line);
    ss>>n >>p;
 for(int i=0;i<p;i++)
 {
     ss>>arr[i];
 }
 best=0;
 solve(0,0);

 for(int i=0;i<pathMax.size();i++)
 {
     cout << pathMax[i] << " ";
 }
 cout << "sum:" << best << endl;

}
    return 0;
}