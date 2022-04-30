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
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end()) // if this number does not exist in the map yet
                mp[nums[i]]=1;
            else
                mp[nums[i]]++;
        }
        vector<int> sol;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==2)
                sol.push_back(it->first);
        }
        return sol;

    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    Solution S;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> sol = S.findDuplicates(nums);
    for(int i=0;i<sol.size();i++)
        cout << sol[i] << " ";
    cout << endl;

    vector<int> nums2 = {1,1,2};
    vector<int> sol2 = S.findDuplicates(nums2);
    for(int i=0;i<sol2.size();i++)
        cout << sol2[i] << " ";
    cout << endl;

    vector<int> nums3 = {1};
    vector<int> sol3 = S.findDuplicates(nums3);
    for(int i=0;i<sol3.size();i++)
        cout << sol3[i] << " ";
    cout << endl;

    return 0;
}