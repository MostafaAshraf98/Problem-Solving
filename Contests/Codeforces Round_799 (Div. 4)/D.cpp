#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

bool checkPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string time;
        cin >> time;
        int x;
        cin >> x;
        string delimiter = ":";
        size_t pos = time.find(delimiter);
        int HH = stoi(time.substr(0, pos));
        time.erase(0, pos + delimiter.length());
        int MM = stoi(time);

        int hoursJump = x / 60;
        int minutesJump = x % 60;
        unordered_map<string, bool> mp;
        int countPalindroms = 0;
        while (true) {
            string hours = to_string(HH);
            string minutes = to_string(MM);
            if (hours.size() == 1)
                hours = "0" + hours;
            if (minutes.size() == 1)
                minutes = "0" + minutes;
            string currentTime = hours + minutes;
            if (mp.find(currentTime) == mp.end())
                mp[currentTime] = true;
            else
                break;
            if (checkPalindrom(currentTime))
                countPalindroms++;
            HH += hoursJump;
            MM += minutesJump;
            if (MM >= 60) {
                HH++;
                MM %= 60;
            }
            if (HH >= 24)
                HH %= 24;

        }
        cout << countPalindroms << endl;
    }
    return 0;
}