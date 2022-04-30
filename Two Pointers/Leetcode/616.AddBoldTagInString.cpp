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
    string addBoldTag(string s, vector<string> &words) {
        set<int> starts;
        set<int> ends;
        for (int i = 0; i < words.size(); i++) {
            int pos = 0;
            int index_str;
            while ((index_str = s.find(words[i], pos)) != string::npos) {
                starts.insert(index_str);
                ends.insert(index_str + words[i].size());
                pos = index_str + 1;
            }
        }
        if (starts.size()==0)
            return s;
        auto ptr1Start = starts.begin();
        auto ptr2Start = starts.begin();
        ptr2Start++;
        auto ptrEnd = ends.begin();
        int addedSize=0;
        vector<int> finalStarts;
        vector<int> finalEnds;

        while (ptr2Start != starts.end() && ptrEnd!=ends.end()) {

            if (*ptr2Start > *ptrEnd) // keda ana 3adeito w lazem a2fel
            {
                finalStarts.push_back(*ptr1Start);
                finalEnds.push_back(*ptrEnd);
                ptr1Start = ptr2Start;
                ptr2Start++;
                ptrEnd++;

            }
            else
            {
                ptr2Start++;
                ptrEnd++;
            }
        }

        finalStarts.push_back(*ptr1Start);
        ptrEnd=ends.end();
        ptrEnd--;
        finalEnds.push_back(*ptrEnd);

        for(int i=0;i<finalStarts.size();i++)
        {
            s.insert(finalStarts[i]+addedSize, "<b>");
            addedSize+=3;
            s.insert(finalEnds[i]+addedSize, "</b>");
            addedSize+=4;
        }

        return s;
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