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
    string reverseWords(string s) {
        stack<string> st;
        int ptr1 = 0;
        while (ptr1 < s.size() && s[ptr1] == ' ')
            ptr1++;
        int ptr2 = ptr1 + 1;
        string currentWord = "";
        currentWord += s[ptr1];
        while (ptr2 < s.size()) {
            if (s[ptr2] == ' ') {
                if (currentWord.size() != 0 && currentWord != " ")
                    st.push(currentWord);
                ptr1 = ptr2 + 1;
                while (ptr1 < s.size() && s[ptr1] == ' ')
                    ptr1++;
                currentWord = "";
                if (ptr1 < s.size())
                    currentWord += s[ptr1];
                ptr2 = ptr1 + 1;
            } else {
                currentWord += s[ptr2];
                ptr2++;
            }
        }
        if (currentWord.size() != 0 && currentWord != " ")
            st.push(currentWord);
        string answer = "";
        while (!st.empty()) {
            string word = st.top();
            st.pop();
            answer += word;
            answer += " ";
        }
        answer.pop_back();
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