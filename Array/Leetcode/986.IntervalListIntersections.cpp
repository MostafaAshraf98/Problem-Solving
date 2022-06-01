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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        int it1=0;
        int it2=0;
        vector<vector<int>> result;
        while(it1!=firstList.size()&& it2!=secondList.size())
        {
            vector<int> interval1= firstList[it1];
            vector<int> interval2= secondList[it2];

            int start = max(interval1[0],interval2[0]);
            int end = min(interval1[1],interval2[1]);
            if(start<=end)
            {
                vector<int> intersection;
                intersection.push_back(start);
                intersection.push_back(end);
                result.push_back(intersection);
            }
            if(interval1[1]<interval2[1])
                it1++;
            else
                it2++;

        }
        return result;
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