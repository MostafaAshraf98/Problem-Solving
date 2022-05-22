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

//https://leetcode.com/problems/design-a-leaderboard/

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

class Leaderboard {
public:
    unordered_map<int,int> mp;

    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        if(mp.find(playerId) == mp.end()) // if this player does not exist
            mp[playerId] = score;
        else
            mp[playerId]+=score;
    }

    int top(int K) {
        int count =0;
        int result=0;
        vector<pair<int,int>> v;
        for(auto it: mp)
            v.push_back(it);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i< K;i++)
        {
            if(i>= v.size())
                break;
            result += v[i].second;
        }
        return result;
    }

    void reset(int playerId) {
        mp[playerId]=0;
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