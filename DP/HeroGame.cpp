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
int a1, a2, b1, b2;

ii solve(vector<vector<ii>> &memo, int turn, int currentHealth, int oponentHealth) {

    if (currentHealth <= 0 && oponentHealth > 0) // i lost
// the first in the pair is the number of turn from this point next, and the second is the winning player
        return make_pair(0, (turn + 1) % 2);
    else if (currentHealth > 0 && oponentHealth <= 0) // i won
        return make_pair(0, turn);
    else if (currentHealth <= 0 && oponentHealth <= 0) // i won
    {
        return make_pair(0, turn);
    }
    //--------------------------------------------------------
    if (memo[currentHealth][oponentHealth].second != -1) {
        if (memo[currentHealth][oponentHealth].second == 0)// i won
            return make_pair(memo[currentHealth][oponentHealth].first, turn);
        else
            return make_pair(memo[currentHealth][oponentHealth].first, (turn + 1) % 2);
    }
    //----------------------------------------------------
    ii actionA = solve(memo, (turn + 1) % 2, oponentHealth - a2, currentHealth - a1);
    ii actionB;
    if (currentHealth % 3 == 0)
        actionB = solve(memo, (turn + 1) % 2, oponentHealth - b1, currentHealth);
    else
        actionB = solve(memo, (turn + 1) % 2, oponentHealth - b2, currentHealth - b2);
//----------------------------------------------------
    if (turn == 0) {
        if (actionA.second == 0 && actionB.second == 1)// if he won in scenario A but lost in scenario b
            memo[currentHealth][oponentHealth] = make_pair(1 + actionA.first, 0);

        else if (actionA.second == 1 && actionB.second == 0) // if he lost in actiona and won in action b
            memo[currentHealth][oponentHealth] = make_pair(1 + actionB.first, 0);

        else if (actionA.second == 0 && actionB.second == 0) // won in both
            memo[currentHealth][oponentHealth] = make_pair(1 + max(actionA.first, actionB.first), 0);

        else if (actionA.second == 1 && actionB.second == 1) // lost in both
            memo[currentHealth][oponentHealth] = make_pair(1 + min(actionA.first, actionB.first), 1);
    } else {

        if (actionA.second == 1 && actionB.second == 0)
            memo[currentHealth][oponentHealth] = make_pair(1 + actionA.first,
                                                           0);

        else if (actionA.second == 0 && actionB.second == 1) // if he lost in actiona and won in action b
            memo[currentHealth][oponentHealth] = make_pair(1 + actionB.first, 0);


        else if (actionA.second == 1 && actionB.second == 1) // won in both
            memo[currentHealth][oponentHealth] = make_pair(1 + max(actionA.first, actionB.first), 0);

        else if (actionA.second == 0 && actionB.second == 0) // lost in both
            memo[currentHealth][oponentHealth] = make_pair(1 + min(actionA.first, actionB.first), 1);
    }


    if (memo[currentHealth][oponentHealth].second == 0)// i won
        return make_pair(memo[currentHealth][oponentHealth].first, turn);
    else
        return make_pair(memo[currentHealth][oponentHealth].first, (turn + 1) % 2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int n; // the health if the players
    sff(n, a1);
    sff(a2, b1);
    sf(b2);
    vector<vector<ii>> memo(n + 1, vector<ii>(n + 1, make_pair(-1, -1)));
    ii turns = solve(memo, 0, n, n);
    if (turns.second == 0) // then player 1 won
    {
        pfs("1 ");
        pf(turns.first);
        nl;
    } else // player 2
    {
        pfs("2 ");
        pf(turns.first);
        nl;
    }
    return 0;
}