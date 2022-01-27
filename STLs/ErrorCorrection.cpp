#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e3;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=482
// ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    while (cin >> n && n!=0) {
        int SumRows[N]; // index is row number and value is the parity
        int SumColumns[N];
        memset(SumRows,0,N);
        memset(SumColumns,0,N);

        for (int row = 1; row <= n; row++) {
            for (int column = 1; column <= n; column++) {
                int x;
                cin >> x;
                SumRows[row] += x;
                SumColumns[column] += x;
            }
        }
        int numberOfOddRows = 0;
        int numberOfOddColumns = 0;
        int indexCorruptedRow;
        int indexCorruptedColumn;

        for (int i = 1; i <= n; i++) {
            if (numberOfOddColumns > 1 || numberOfOddColumns > 1)
                break;
            if (SumRows[i] % 2 != 0) {
                numberOfOddRows++;
                indexCorruptedRow = i;
            }
            if (SumColumns[i] % 2 != 0) {
                numberOfOddColumns++;
                indexCorruptedColumn = i;
            }
        }
        if (numberOfOddColumns == 1 && numberOfOddRows == 1) {
            cout << "Change bit (" << indexCorruptedRow << "," << indexCorruptedColumn << ")" << endl;
        } else if (numberOfOddColumns == 0 && numberOfOddRows == 0) { cout << "OK" << endl; }
        else
            cout << "Corrupt" << endl;

    }
    return 0;
}