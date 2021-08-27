#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

// https://codeforces.com/problemset/problem/250/C
// ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n, k;
    cin >> n >> k;
    map<int, int> genresCountInterrupts; // count STRESSES that will be reduced IF WE TRIED TO REMOVE EACH TYPE OF GENRE
    vi days;
    for (int i = 1; i <= k; i++)
        genresCountInterrupts[i] = 0;
    days.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (days.empty()) {
            days.push_back(x);
        } else if (days[days.size() - 1] != x)
            days.push_back(x);
    }
    days.push_back(0);
    for (int i = 1; i < days.size() - 1; i++) {
        if (days[i - 1] == days[i + 1])
            genresCountInterrupts[days[i]] += 2;
        else
            genresCountInterrupts[days[i]] += 1;
    }
    int genreMax;
    int max = -1;
    for (auto it = genresCountInterrupts.begin();
         it != genresCountInterrupts.end(); it++) // yeb2a howa kan el sabab f stress 3ala el fadi
    {
        if (it->second > max) {
            max = it->second;
            genreMax = it->first;
        }
    }
    cout << genreMax << endl;
    return 0;
}

//el fekra eni 3ayez a3raf anhi aktar wa7ed eli 3ala yemino w shemalo arkam mo5talefa mesh nafs el rakam
//awel 7aga keda keda heya en law nafs el rakam da5al wara ba3do hashil el duplicates w a5alih ka2eno da5al mara wa7da
//w eni a3mel map l kol genre (rakam) w a2oul en law eli yemino w shemalo mo5talefin azawed el count 1 w a0return el genre with the maximum count
// hena el count represents the number of stress eli hatetshal law shel t el genre di
