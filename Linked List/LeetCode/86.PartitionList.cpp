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

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        vector<ListNode *> less;
        vector<ListNode *> greaterOrEqual;
        while (head != NULL) {
            if (head->val < x)
                less.push_back(head);
            else
                greaterOrEqual.push_back(head);
            head = head->next;
        }
        if (less.size() == 0)
            return greaterOrEqual[0];
        ListNode *answer = less[0];
        ListNode *temp = less[0];
        for (int i = 1; i < less.size(); i++) {
            temp->next = less[i];
            temp = temp->next;
        }
        for (int i = 0; i < greaterOrEqual.size(); i++) {
            temp->next = greaterOrEqual[i];
            temp = temp->next;
        }
        temp->next = NULL;
        return answer;

    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}