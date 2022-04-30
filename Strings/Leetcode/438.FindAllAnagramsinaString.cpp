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
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (p.size() > s.size())
            return result;

        map<char, int> letters;
        for (int i = 0; i < p.size(); i++) {
            if (letters.find(p[i]) == letters.end())
                letters[p[i]] = 1;
            else
                letters[p[i]]++;
        }
        map<char, int> currentSet;
        for (int i = 0; i < p.size(); i++) {
            if (currentSet.find(s[i]) == currentSet.end())
                currentSet[s[i]] = 1;
            else
                currentSet[s[i]]++;
        }
        int ptr1 = 0;
        int ptr2 = p.size() - 1;
        while (true) {
            if (currentSet == letters)
                result.push_back(ptr1);
            //remove first and add last
            currentSet[s[ptr1]]--;
            if (currentSet[s[ptr1]] == 0)
                currentSet.erase(s[ptr1]);
            ptr1++;
            ptr2++;
            if (ptr2 == s.size())
                break;
            //inset last element
            if (currentSet.find(s[ptr2]) == currentSet.end())
                currentSet[s[ptr2]] = 1;
            else
                currentSet[s[ptr2]]++;
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