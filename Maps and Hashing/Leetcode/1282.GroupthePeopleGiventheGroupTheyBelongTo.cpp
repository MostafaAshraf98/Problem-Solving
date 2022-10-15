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
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        multimap<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++) {
            auto result = mp.equal_range(groupSizes[i]);
            if (distance(result.first, result.second) == 0) // then this group size does not exist
            {
                // insert it
                vector<int> v;
                v.push_back(i);
                mp.insert(make_pair(groupSizes[i], v));
            } else {
                auto temp= result.first;
                for (auto it = result.first; it != result.second; it++){
                    temp=it;
                }
                auto lastGroup = temp;

                if (lastGroup->second.size() == groupSizes[i]) // then insert a new one
                {
                    vector<int> v;
                    v.push_back(i);
                    mp.insert(make_pair(groupSizes[i], v));
                } else {
                    lastGroup->second.push_back(i);
                }
            }
        }
        vector<vector<int>> answer;
        for(auto it= mp.begin();it!=mp.end();it++)
        {
            answer.push_back(it->second);
        }
        return answer;
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