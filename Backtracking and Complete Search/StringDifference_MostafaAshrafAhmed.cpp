#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

void solve(int n, int h, int countOnes, string currentString, vector<string> &solutions) {
    //state:
    //n: the length of the binary string (fixed)
    //h: the number of ones in the string (fixed)
    //countOnes; the number of ones in the current string (changes)
    //currentString: the string we have so far in this state (changes)
    //solutions: the vector of solutions (changes in base)

    //base:
    if ((int)currentString.length() == n) {
        if (countOnes == h)
            solutions.push_back(currentString);
        return;
    }

    //transitions
    //take 0
    solve(n, h, countOnes, currentString + "0", solutions);

    //take 1
    solve(n, h, countOnes + 1, currentString + "1", solutions);

}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int N; //the length of the binary string
    int H; // the number of ones in the string
    cin >> N >> H;
    vector<string> solutions;
    solve(N, H, 0, "", solutions);
    for (int i = 0; i < (int)solutions.size(); i++) {
        cout << solutions[i] << endl;
    }


    return 0;
}