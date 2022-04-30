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

class WordDistance {
public:
    unordered_map<string, vector<int>> mp;

    WordDistance(vector<string> &wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            if (mp.find(wordsDict[i]) == mp.end()) {
                vector<int> v;
                v.push_back(i);
                mp[wordsDict[i]] = v;
            } else {
                mp[wordsDict[i]].push_back(i);
            }
        }
    }

    int shortest(string word1, string word2) {
        vector<int> v1 = mp[word1];
        vector<int> v2 = mp[word2];
        int ptr1 = 0;
        int ptr2 = 0;
        int minDist = INT_MAX;
        while (ptr1 != v1.size() || ptr2 != v2.size()) {
            if (ptr1 == v1.size()) {
                int dist = abs(v1[ptr1 - 1] - v2[ptr2]);
                if (dist < minDist)
                    minDist = dist;
                ptr2++;
            } else if (ptr2 == v2.size()) {
                int dist = abs(v2[ptr2 - 1] - v1[ptr1]);
                if (dist < minDist)
                    minDist = dist;
                ptr1++;
            } else {
                int dist = abs(v1[ptr1] - v2[ptr2]);
                if (dist < minDist)
                    minDist = dist;
                if (v1[ptr1] > v2[ptr2])
                    ptr2++;
                else if (v1[ptr1] < v2[ptr2])
                    ptr1++;
                else
                    return 0;
            }
        }
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