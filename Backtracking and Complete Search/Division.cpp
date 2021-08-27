#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=666
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int a, b;
    int n;
    bool first = true;
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<pair<int, int> > v[100]; // Vector of vectors (index holds the vector of all pairs satisfying condition) w mosta7il el division tedi 7aga akbar mel 100
    // 3alashan 3andi 4 digit number (max = 98765) divided by 4 digit number (min = 01234) gives a number lessa than 100

    do {
        a = nums[0] * 10000 + nums[1] * 1000 + nums[2] * 100 + nums[3] * 10 + nums[4];
        b = nums[5] * 10000 + nums[6] * 1000 + nums[7] * 100 + nums[8] * 10 + nums[9];

        if (a % b == 0) {
            v[a / b].push_back(make_pair(a, b));
        }
    } while (next_permutation(nums, nums + 10));

    while (cin >> n && n!=0) {

        if (!first)
            cout << endl;

        if (v[n].size() == 0) {
            cout << "There are no solutions for " << n << "." << endl;
        } else {
            for (int i = 0; i < v[n].size(); i++) {
                cout << v[n][i].first << " / " << (v[n][i].second < 10000 ? "0" : "")  << v[n][i].second << " = " << n // meaning that if the second number starts with 0 i will explicitly put it as it was removed
                     << endl;
            }
        }
        first = false;
    }

    return 0;
}