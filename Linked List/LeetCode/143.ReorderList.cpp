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
    void reorderList(ListNode *head) {
        ListNode *ptr = head;
        int count = 0;

        //counting the number of elementing in the linked list to get the middle nodes
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        int n = ceil(count / 2.0);
        ptr = head;
        for (int i = 0; i < n - 1; i++) {
            ptr = ptr->next;
        }
        //Now ptr is the node before the middle one to the two lists
        ListNode *curr = ptr->next; // the start of the second list
        ptr->next = NULL; // detach the first list
        ListNode *prev = NULL;
        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr; // move one to the right ... the previous becomes the current
            curr = temp; // and the current becomes the next (the value in the temp)
        }
        //now prev is the first element in the second linked list
        //Head is the first element in the first linked list

        while (prev != NULL) {
            ListNode *temp = prev->next;
            prev->next = head->next;
            head->next = prev;
            prev = temp;
            head = head->next->next;
        }
        return;

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