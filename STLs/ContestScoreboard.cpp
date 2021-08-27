#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;
map<int, int> score;
map<int, int> timeAc;
map<int, set<int>> solved;
map<int, map<int, int>> incorrect;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1199
//ACCEPTED

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b) { // true ma3naha matbadelsh ( fel sorting function )
    if (a.second > b.second)
        return true;
    else if (a.second == b.second) {
        if (timeAc[a.first] >=
            timeAc[b.first]) // if they have the same score but the accumulated time of a is less than the accumulated time of b
            return false;
        else
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string line;

    int t;
    cin >> t;
    getline(cin, line);
    getline(cin, line);
    for (int i = 0; i < t; i++) {
        score.clear();
        timeAc.clear();
        solved.clear();
        incorrect.clear();
        while (getline(cin, line) && line != "") {
            istringstream stream(line);
            int contestant;
            int problem;
            int time;
            char c;
            stream >> contestant >> problem >> time >> c;
            if (score.find(contestant) == score.end()) // if this contestant is not registered in the map yet
            {
                timeAc[contestant] = 0;
                score[contestant] = 0;
            }
            if (c == 'C' && solved[contestant].find(problem) == solved[contestant].end()) {
                score[contestant]++;
                timeAc[contestant] += time;
                timeAc[contestant] += incorrect[contestant][problem] * 20;
                solved[contestant].insert(problem);
            } else if (c == 'I') {
                if (incorrect.find(contestant) == incorrect.end() || incorrect[contestant].find(problem) ==
                                                                     incorrect[contestant].end()) // if it is the first submission to the contestant or first submission for this problem
                    incorrect[contestant][problem] = 1;
                else // if the problem was submitted before
                    incorrect[contestant][problem]++;

            }
        }
        //Here we want to sort the map of score based on the highest score first ( the value not the key )
        vii v;
        for (auto it = score.begin(); it != score.end(); it++) {
            v.push_back(make_pair(it->first, it->second));
        }
        sort(v.begin(), v.end(), sortByVal);

        for (int i = 0; i < v.size(); i++) {
            int minVal = v[i].first;
            int minIndex = -1;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i].second == v[j].second && timeAc[v[i].first] == timeAc[v[j].first] && minVal > v[j].first) {
                    minVal = v[j].first;
                    minIndex = j;
                }
            }
            if (minIndex != -1) {
                auto temp = v[i];
                v[i] = v[minIndex];
                v[minIndex] = temp;
            }
        }

        for (auto it = v.begin(); it != v.end(); it++) {
            int s = it->second;
            int t = timeAc[it->first];
            cout << it->first << " " << s << " " << t << endl;

        }
        if (i != t - 1)
            cout << endl;
    }


    return 0;
}