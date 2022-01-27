#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define endl '\n';
int target = 27;
bool found = false;

void solve(const int(&numbers)[5], ll total, int index, string s) {
    //state:
    //numbers: the array of numbers with the current permutation
    //total: the arithmetic output so far
    //index: the index of the number we are handling in this state
    //s: holds the expression (just for debugging)

    //base
    if (index == 5) {
        if (total == target) {
//            cout << s << endl;
            found = true;
        }
        return;
    }
    if (found)
        return;

    //transitions
    //+
    solve(numbers, total + numbers[index], index + 1, s + "+" + to_string(numbers[index]));

    //-
    solve(numbers, total - numbers[index], index + 1, s + "-" + to_string(numbers[index]));

    //*
    solve(numbers, total * numbers[index], index + 1, s + "*" + to_string(numbers[index]));

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif

    int numbers[5];
    for (int i = 0; i < 5; i++)
        cin >> numbers[i];
    sort(numbers,numbers+5);
    do {
        solve(numbers, numbers[0], 1, to_string(numbers[0]));
    } while (next_permutation(numbers, numbers + 5) && !found);

    if (found) {
        cout << "Possible" << endl;
    } else
        cout << "Impossible" << endl;

    return 0;
}