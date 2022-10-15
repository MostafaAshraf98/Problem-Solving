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

///1111111111000000
class Solution {
public:

    bool valid (vector<int> & heights, int bricks,int ladders, int target)
    {
        vector<int> climbs;
        for(int i=0;i<target;i++)
        {
            if(heights[i]< heights[i+1])
                climbs.push_back(heights[i+1]-heights[i]);
        }
        sort(climbs.begin(),climbs.end());
        for(int climb: climbs)
        {
            if(bricks>=climb)
                bricks-=climb;
            else if (ladders>0)
                ladders--;
            else
                return false;

        }
        return true;
    }

    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int st = 0;
        int end = heights.size()-1;
        while (st<end)
        {
            int mid = st + (end-st+1)/2;
            if(valid(heights,bricks,ladders,mid))
                st= mid;
            else
                end = mid-1;
        }
        return st;
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