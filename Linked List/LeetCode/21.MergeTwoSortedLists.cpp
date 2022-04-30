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


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *newHead = NULL;
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *curr = NULL;
        if (ptr1->val >= ptr2->val) {
            ListNode *n = new ListNode(ptr2->val);
            newHead = n;
            ptr2 = ptr2->next;
        } else {
            ListNode *n = new ListNode(ptr1->val);
            newHead = n;
            ptr1 = ptr1->next;
        }
        curr = newHead;
        while (ptr1 != NULL || prt2 != NULL) {
            if (ptr1 == NULL) {
                ListNode *n = new LinkedNode(ptr2->val);
                curr->next = n;
                curr = curr->next;
                ptr2 = ptr2->next;
                continue;
            }
            if (ptr2 == NULL) {
                ListNode *n = new LinkedNode(ptr1->val);
                curr->next = n;
                curr = curr->next;
                ptr1 = ptr1->next;
                continue;
            }
            if (ptr1->val >= ptr2->val) {
                ListNode *n = new ListNode(ptr2->val);
                curr->next = n;
                curr = curr->next;
                ptr2 = ptr2->next;
            } else {
                ListNode *n = new ListNode(ptr1->val);
                curr->next = n;
                curr = curr->next;
                ptr1 = ptr1->next;
            }
        }
        return newHead;
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