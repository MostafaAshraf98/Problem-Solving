#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

// https://codeforces.com/problemset/problem/22/D
//ACCEPTED

bool comp(const ii &p1, const ii &p2) {
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    vii segments;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= y)
            segments.push_back(make_pair(x, y));
        else
            segments.push_back(make_pair(y, x));
    }
    sort(segments.begin(), segments.end(), comp);
    int countNails = 0;
    int coordinateLastNail = -1*INF;
    vi coordinates;
    for (int i = 0; i < segments.size(); i++) {
        if (segments[i].first <= coordinateLastNail)
            continue;
        countNails++;
        coordinateLastNail = segments[i].second;
        coordinates.push_back(segments[i].second);
    }

    cout << countNails << endl;
    for (int i = 0; i < coordinates.size(); i++)
        cout << coordinates[i] << " ";
    cout << endl;

    return 0;
}

//fekret el mas2ala shabah A-Restaurant heya enak bete3mel sort lel segments based 3ala min beye5las el awel
// w 7atet variable (coordinateLastNail) bey2oul eni ebtadeit mel awel 5ales
// fa da ma3nah en law ana mashi b tartib min bey5alas el awel yeb2a ana ha8atii kolo
// w ba7ot Nail fel end beta3 el segment law el nail eli fat makansh me8ati bedayto
// 3alashan an wasek en el segment eli abli 5eles abl da