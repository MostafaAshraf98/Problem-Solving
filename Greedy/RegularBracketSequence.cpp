#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/problemset/problem/26/B
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
   char x;
   int count =0; // keeps track of open brackets
   int result=0; // counts brackets
   while(cin>>x)
   {
       if(x=='(')
           count++;
       else
       {
           if (count!=0)
           {
               count--;
               result+=2;
           }
       }
   }
   cout << result << endl;
    return 0;
}