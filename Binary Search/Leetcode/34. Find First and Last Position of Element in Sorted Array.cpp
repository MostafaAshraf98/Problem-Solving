#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
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
    int indexGreater(vector<int>& nums,int target)
    {
        int start =0;
        int end = nums.size()-1;
        while(start<end)
        {
            int mid = start+ (end-start)/2;
            if(nums[mid]>target)
                end=mid;
            else 
                start = mid+1;
        }
        return start;
    }
    int indexLess(vector<int>&nums,int target,int end)
    {
        int start = 0;
        while(start<end)
        {
            int mid = start + (end-start+1)/2;

            if(nums[mid]<target)
                start = mid;
            else
                end = mid-1;
        }
        return start;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        
        vector<int>result;
        int greater = indexGreater(nums,target);
        int less = indexLess(nums,target,greater);

        if(nums[less]==target)
            result.push_back(less);
        else if(less+1<nums.size() && nums[less+1]==target)
            result.push_back(less+1);
        else 
            return {-1,-1};

        if(nums[greater]==target)
            result.push_back(greater);
        else if(greater-1>=0 && nums[greater-1]==target)
            result.push_back(greater-1);
        else 
            return {-1,-1};

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