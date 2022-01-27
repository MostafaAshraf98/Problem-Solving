#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

void solve(int n, vector<vector<vi>> v, int currentCount, int &minCount, int currentFloor, int i, int j) {
    //state:
    //n: the number of rooms and floors (fixed)
    //v: the matrix that holds the gold (fixed)
    //currentCount: the current count of gold payed (changes)
    //minCount: the best answer so far (changes in base)
    //currentFloor: the floor (changes)
    //i: row in this floor (changes)
    //j: column in this room (changes)

    //base
    if (currentFloor == n || i == n || j == n)
        return;
    currentCount += v[currentFloor][i][j];
    if (currentFloor == n - 1 && i == n - 1 && j == n - 1) {
        if (currentCount < minCount || minCount == -1)
            minCount = currentCount;
        return;
    }
    if (currentCount >= minCount && minCount != -1)
        return;

    //transitions

    //move right in the same floor
    solve(n, v, currentCount, minCount, currentFloor, i, j + 1);

    //move bottom in the same floor
    solve(n, v, currentCount, minCount, currentFloor, i + 1, j);

    //move to the next floor up
    solve(n, v, currentCount, minCount, currentFloor + 1, i, j);


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<vector<int>>> matrix(n, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int i = 0; i < n; i++) // the floor
    {
        for (int j = 0; j < n; j++) // the row
        {
            for (int k = 0; k < n; k++)// the column
            {
                cin >> matrix[i][j][k];
            }
        }
    }
    int minCount = -1;
    solve(n, matrix, 0, minCount, 0, 0, 0);
    cout << minCount << endl;

    return 0;
}