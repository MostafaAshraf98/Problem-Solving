#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/contest/65/problem/B
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    int it=0;
    int y=1000;
    while(y!=2012)
    {
        string current = to_string(y);
        if(it==v.size())
            break;
        if(v[it]==current)
        {
            it++;
            continue;
        }
        for(int i=0;i<4;i++)
        {
            char temp = v[it][i];
            if(v[it][i]!=current[i])
            {
                v[it][i]=current[i];
                if(v[it]!=current)
                {
                    v[it][i]=temp;
                    y++;
                }
                else
                    it++;
                break;
            }
        }
    }
    if(it!=v.size())
    {
        cout << "No solution" << endl;
        return 0;
    }
    for(int i=0;i<v.size();i++)
        cout << v[i]<< endl;
    return 0;
}

//This problem can be solved by adopting a greedy algorithm. We first introduce a variable Y which is initialized with value 1000, i.e., the minimum year that meets the requirements.
// Then, we enumerate the input integers in the given order. For each integer, we start with the current Y, and increase Y by 1 until it reaches 2011.
// During this process, we check whether we can convert this integer into Y by changing no more than one digit. If the answer is yes, we can immediately stop the loop and just
// replace this integer with the current value of Y, and store the current Y for the next loop which deals with the next integer; otherwise it means that there is no solution.