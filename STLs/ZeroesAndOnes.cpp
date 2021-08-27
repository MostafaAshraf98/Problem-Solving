#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1265
//Accepted

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    string str;
        int n;
    int Case = 1;
    while (cin >> str >> n) {
        printf("Case %d:\n", Case);
        Case++;
        while(n--) {
            bool ans = true;
            int start, end;
            cin >> start >> end;

            if (end < start)
            {
                int temp = end;
                end = start;
                start = temp;
            }
            for (int i = start ; i < end; i++) {
                if (str[i] != str[i+1]) {
                    ans = false;
                    break;
                }
            }
            //  ans = all_of(str.begin() + start, str.begin() + end + 1, [ch](char c) { return c == ch; });
            if (ans)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}