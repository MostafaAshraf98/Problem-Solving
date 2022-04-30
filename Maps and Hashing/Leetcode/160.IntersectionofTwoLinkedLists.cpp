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

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, bool> mp1;
        map<ListNode *, bool> mp2;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        mp1[ptr1] = true;
        mp2[ptr2] = true;

        if (ptr1 == NULL || ptr2 == NULL)
            return NULL;
        if (ptr1 == ptr2)
            return ptr1;

        while (true) {
            if (ptr1 == NULL && ptr2 == NULL)
                return NULL;
            if (ptr1 != NULL) {
                ptr1 = ptr1->next;
                if (mp2.find(ptr1) != mp2.end())
                    return ptr1;
                mp1[ptr1] = true;
            }
            if (ptr2 != NULL) {
                ptr2 = ptr2->next;
                if (mp1.find(ptr2) != mp1.end())
                    return ptr2;
                mp2[ptr2] = true;
            }
        }
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