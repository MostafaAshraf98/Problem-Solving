#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)
#define sfs(s) scanf("%s", s)

#define pf(n) printf("%d", n)
#define pff(n, m) printf("%d %d", n, m)
#define pfl(n) printf("%I64d", n)
#define pffl(n, m) printf("%I64d %I64d", n, m)
#define pfs(s) printf("%s", s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int)10e4;

class Solution
{
public:
    int k;
    int n;

    vector<vector<int>> combine(int n, int k)
    {
        this->k = k;
        this->n = n;
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(curr, 1, ans);
        return ans;
    }

    void backtrack(vector<int> &curr, int firstNum, vector<vector<int>> &ans)
    {
        if (curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        int need = k - curr.size();
        int remain = n - firstNum + 1;
        int available = remain - need;

        for (int num = firstNum; num <= firstNum + available; num++)
        {
            curr.push_back(num);
            backtrack(curr, num + 1, ans);
            curr.pop_back();
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}