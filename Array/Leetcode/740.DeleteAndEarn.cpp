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
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end()) // if it already exists
                mp[nums[i]]++;
            else
                mp[nums[i]]=1;
        }
        sort(nums.begin(),nums.end());
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        vector<int> memo(nums.size(),-1);
        return solve(nums,mp,memo,0);
    }

    int solve(vector<int>&nums,map<int,int>&mp, vector<int>& memo,int index)
    {
        if(index>= nums.size())
            return 0;

        if(memo[index]!=-1)
            return memo[index];
        bool jump2 = false;
        if(index+1<nums.size() && nums[index+1]==nums[index]+1)
            jump2=true;

        //take
        int take;
        if(!jump2)
            take = nums[index]*mp[nums[index]] + solve(nums,mp,memo,index+1);
        else
            take = nums[index]*mp[nums[index]] + solve(nums,mp,memo,index+2);
        int leave = solve(nums,mp,memo,index+1);
        return memo[index] = max(take,leave);

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