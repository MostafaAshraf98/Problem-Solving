#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1975
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int c; // numberof test cases
    cin >> c;
    while (c--) {
    int l; // length of ferry in cm
    int m; // number of cars
    int count=0; // count of times back and forth
    char currentLoc='l'; // location of the ferry
    queue<int> left; // queue FIFO of cars lengths left in (cm)
    queue<int> right; // " right
    cin>>l>>m;
    l*=100;
    int length=l;
    for(int i=0;i<m;i++)
    {
        int x;
        string loc;
        cin>>x>>loc;
        if(loc=="right")
            right.push(x);
        else
            left.push(x);
    }
while(!left.empty() || !right.empty())
{
    l=length;
    if(currentLoc=='l')
    {
        while(1)
        {
            if(!left.empty() && l>left.front())
            {
                l-=left.front();
                left.pop();
            }
            else
            {
                count++;
                currentLoc='r';
                break;
            }
        }
    }
    else
    {
        while(1)
        {
            if(!right.empty() && l>right.front())
            {
                l-=right.front();
                right.pop();
            }
            else
            {
                count++;
                currentLoc='l';
                break;
            }
        }
    }

}
cout << count << endl;
    }
    return 0;
}

// Ferket el mas2ala eni ba3mel simulation lel situtation
// ba7ott el lengths of cars 3ala el yemin wel shemal f queues (FIFO)
// ba3abar 3an el ferry bel length l in cm bardo wel location beta3ha left or right
// ma3 kol laffa el length beyeb2a 3ala a5ro w a3od amla fiha l 7ad ma el length mayesma7sh l 3arabeya kaman
// and so on l 7ad ma el 2 queus yefdo