#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
string arrWords[100];
string rule;
vector<string> v;
vector<string>currentWord;


//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=569
//ACCEPTED

int n;//number of words in the dictionary
int m; // number of rules

void solve(int pos) {
        if(pos== rule.size())
        {
            string result="";
            for(int i=0;i<currentWord.size();i++)
            {
                result+=currentWord[i];
            }
            v.push_back(result);
            return;
        }
        if(rule[pos]=='0')
        {
            for(int i=0;i<=9;i++)
            {
                //do recurse undo
                string x = to_string(i);
                currentWord.push_back(x);
                solve(pos+1);
                currentWord.pop_back();
            }
        } else
        {
            for(int i=0;i<n;i++)
            {
                currentWord.push_back(arrWords[i]);
                solve(pos+1);
                currentWord.pop_back();
            }
        }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    while (cin >> n) {
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> arrWords[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> rule;
            solve(0);
        }
        cout << "--" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }
    return 0;
}