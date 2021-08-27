#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = 11;
int t, n, m;
int Case = 1;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2345
//Accepted

void inc(int Mat[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Mat[i][j] = (Mat[i][j] + 1) % 10;
        }
    }
}

void dec(int Mat[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Mat[i][j]--;
            if(Mat[i][j]==-1)
                Mat[i][j]+=10;
        }
    }
}

void transpose(int Mat[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = Mat[i][j];
            Mat[i][j] = Mat[j][i];
            Mat[j][i] = temp;
        }
    }
}

void row(int Mat[N][N], int a, int b) {
    for (int i = 0; i < n; i++) {
        int temp = Mat[a][i];
        Mat[a][i] = Mat[b][i];
        Mat[b][i] = temp;
    }
}

void col(int Mat[N][N], int a, int b) {
    for (int i = 0; i < n; i++) {
        int temp = Mat[i][a];
        Mat[i][a] = Mat[i][b];
        Mat[i][b] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    cin>>t;
    while (t--) {
        cout << "Case #" << Case << endl;
        Case++;
        cin >> n;
        int Mat[N][N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                cin>>ch;

                Mat[i][j]=ch-48;
            }
        }
        cin >> m;
        for (int k = 0; k < m; k++) {
            string com;
            int a, b;
            cin >> com;
            if (com == "inc")
                inc(Mat);
            if (com == "dec")
                dec(Mat);
            if (com == "transpose")
                transpose(Mat);
            if (com == "row") {
                cin >> a >> b;
                row(Mat, a-1, b-1);
            }
            if (com == "col") {
                cin >> a >> b;
                col(Mat, a-1, b-1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}