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

//https://codeforces.com/problemset/problem/371/C
//ACCEPTED

int hasSausage;
int hasBread;
int hasCheese;
int priceBread;
int priceCheese;
int priceSausage;
int numberOfRequiredSausages = 0;
int numberOfRequiredCheese = 0;
int numberOfRequiredBread = 0;
ll currentMoney;

bool valid(ll numberOfHam) {

    ll requiredMoney = 0;
    ll totalRequiredCheese = numberOfHam * numberOfRequiredCheese;
    ll totalRequiredBread = numberOfHam * numberOfRequiredBread;
    ll totalRequiredSausages = numberOfHam *numberOfRequiredSausages;

    if (numberOfRequiredCheese != 0 && totalRequiredCheese > hasCheese)
        requiredMoney += (totalRequiredCheese - hasCheese) * priceCheese;
    if (numberOfRequiredSausages != 0 && totalRequiredSausages > hasSausage)
        requiredMoney += (totalRequiredSausages - hasSausage) * priceSausage;
    if (numberOfRequiredBread != 0 && totalRequiredBread > hasBread)
        requiredMoney += (totalRequiredBread - hasBread) * priceBread;

    if (requiredMoney > currentMoney)
        return false;
    return true;
}

ll BS() {
    ll st = 0;
    ll end = 10e12;
    while (st < end) {
        ll mid = st + (end - st + 1) / 2;
        if (valid(mid))
            st = mid;
        else
            end = mid - 1;
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    string recipe;
    cin >> recipe;
    cin >> hasBread >> hasSausage >> hasCheese;
    cin >> priceBread >> priceSausage >> priceCheese;
    cin >> currentMoney;
    for (int i = 0; i < recipe.size(); i++) {
        if (recipe[i] == 'S')
            numberOfRequiredSausages++;
        else if (recipe[i] == 'C')
            numberOfRequiredCheese++;
        else
            numberOfRequiredBread++;
    }
    cout << BS() << endl;

    return 0;
}