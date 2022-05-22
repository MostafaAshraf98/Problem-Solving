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

//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrom (vector<string>& v)
    {
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size()/2;j++)
            {
                if(v[i][j]!= v[i][v[i].size()-1-j])
                    return false;
            }
        }
        return true;
    }
    vector<vector<string>> solve(string& s,int index,vector<string> currentVecString)
    {
        if(index == s.size()) // all the letters are added
        {
            vector<vector<string>> v;
            if(isPalindrom(currentVecString))
                v.push_back(currentVecString);
            return v;
        }
        // Transition
        // add it to the previous or not
        string temp = currentVecString[currentVecString.size()-1];
        currentVecString[currentVecString.size()-1] = currentVecString[currentVecString.size()-1] + s[index];
        vector<vector<string>> v1 = solve(s,index+1,currentVecString);

        currentVecString[currentVecString.size()-1] = temp;
        currentVecString.push_back(std::string(&s[index], 1));
        vector<vector<string>> v2 = solve(s,index+1,currentVecString);
        v1.insert(v1.end(),v2.begin(),v2.end());

        return v1;

    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        v.push_back(std::string(&s[0], 1));
        return solve(s,1,v);
    }
};