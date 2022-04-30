#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

class Solution {
public:

    string rec(int n, int index, string s) {
        //State:
        //n: it is the problem input (fixed)
        //index: The current index we are in ... it starts from 1 and ends at n
        //s: the string passed from the previous state (the previous saying)

        //base case
        if (index == 1)
            return rec(n, index + 1, "1");

        //last return

        //other cases
        int count =1;
        char current = s[0];
        string finalString="";
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==current)
            {
                count++;
                continue;
            }
            finalString= finalString+to_string(count) + current;
            count=1;
            current=s[i];
        }
        finalString= finalString+to_string(count) + current;
        if (index == n) {
            //return the final string and not a recursive call
            return finalString;
        }
        else {
            return rec(n,index+1,finalString);
        }
        return "";
    }

    string countAndSay(int n) {
        if(n==1)
            return "1";
        return rec(n,1,"");
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}