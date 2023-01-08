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
const int N = 2* (int) 10e5;

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;

    RandomizedSet() {

    }

    bool insert(int val) {
        if (mp.find(val) == mp.end()) // item is not present
        {
            int index = v.size();
            mp[val] = index;
            v.push_back(val);
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end())
            return false;
        else {
            int indexToDelete = it->second;
            int last = v[v.size()-1];

            v[indexToDelete]=last;
            mp[last] = indexToDelete;

            v.pop_back();
            mp.erase(it);
            return true;
        }
    }

    int getRandom() {
        int randomNumber = rand() % v.size();
        return v[randomNumber];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}