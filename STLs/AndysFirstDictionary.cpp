#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1756
//ACCEPTED

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    set<string> s;
    string str;
    string temp;
    while (cin >> str) { // bamsek kelma kelma
        transform(str.begin(), str.end(), str.begin(), ::tolower);  // ba7awel el kelma di l lower case
        for (int i = 0; i < str.length(); i++) { // bamshy 3ala letter letter mel kelma di
            if (str[i] < 'a' || str[i] > 'z') //law el letter eli masko da mesh alphabetic letter
            {
                temp = str;
                str.erase(i, str.length()); // ba2ta3 el kelma men awelha l 7ad el letter da
                if (str != "") // law kan aslun fih kelma metba2eya
                    s.insert(str); // ba3melaha insert
                else // law tele3 mafish , da ma3nah en awel 7arf mawgoud fel kelma di howa mesh alphabetic
                    temp.erase(i,1); // fa bashil el 7arf da
                str=temp; // beyeb2a 3andi kelma gedida ba3d ma ata3t el kelma eli 3andi
                str.erase(0,i); // ba2ta3 el kelma di men awel
                i=-1; // barga3 l awel el kelma tani

            }
        }
        if (str != "") // law ba3d ma shelt kan fel a5er metba2i kelma a7otaha
            s.insert(str);
    }

    for (auto v:s) {
        cout << v << endl;
    }

    return 0;
}