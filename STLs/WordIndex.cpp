#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
vector<string> arr;

//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=358
// ACCEPTED

bool comp(const string &a, const string &b) {
    if (a.length() > b.length())
        return false;
    else if (a.length() < b.length())
        return true;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string str;
    for (int i = 97; i < 123; i++) { //97 is the ascii of 'a' and 122 is the ascii of 'z'
        string x;
        x = (char) i;
        arr.push_back(x);
        for (int j = i + 1; j < 123; j++) {
            string x;
            x = (char) i;
            x = x + (char) j;
            arr.push_back(x);
            for (int k = j + 1; k < 123; k++) {
                string x;
                x = (char) i;
                x = x + (char) j;
                x = x + (char) k;
                arr.push_back(x);
                for (int y = k + 1; y < 123; y++) {
                    string x;
                    x = (char) i;
                    x = x + (char) j;
                    x = x + (char) k;
                    x = x + (char) y;
                    arr.push_back(x);
                    for (int z = y + 1; z < 123; z++) {
                        string x;
                        x = (char) i;
                        x = x + (char) j;
                        x = x + (char) k;
                        x = x + (char) y;
                        x = x + (char) z;
                        arr.push_back(x);
                    }
                }
            }
        }
    }
    sort(arr.begin(), arr.end(), comp);
    while (cin >> str) {
        bool valid = 1;
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[i] >= str[i + 1]) {
                cout << "0" << endl;
                valid = 0;
                break;
            }
        }
        if (!valid)
            continue;
        auto it = find(arr.begin(), arr.end(), str);
        int index = it - arr.begin();
        index++;
        cout << index << endl;

    }
    return 0;
}

//Fekret el mas2ala eni 3amalt vector fih kol el list of words eli 3ayezha bas mesh sorted
//ba3d keda 3amaltelha sort
//law el kelma eli meda5alhali mesh asceding ba3mel cout l 0 w continue
//8er keda badawar 3al kelma fel array eli ba2et sorted w agib el index eli equal l rakamha