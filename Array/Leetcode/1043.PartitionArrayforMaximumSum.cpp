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

    int getMax(vector<int>& arr,int start,int end)
    {
        int max=-1;
        for(int i=start;i<=end;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        return max;
    }

    int solve(vector<int> &arr, vector<int> &memo, const int &k, int index) {

        if (index == arr.size() - 1)
            return arr[arr.size() - 1];

        if (memo[index] != -1)
            return memo[index];

        int currentMax = 0;
        for (int i = 0; i < k; i++) {
            if(index+i>=arr.size())
                continue;
            int sum = getMax(arr,index,index+i)* (i+1);
            int val =  sum + solve(arr, memo, k, index + i+1);
            if (val > currentMax)
                currentMax = val;
        }
        return memo[index] = currentMax;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        vector<int> memo(arr.size() + 1,-1);
        return solve(arr, memo, k, 0);
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