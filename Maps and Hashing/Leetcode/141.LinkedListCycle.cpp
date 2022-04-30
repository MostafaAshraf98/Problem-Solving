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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *ptr1;
        ListNode *ptr2;
        ptr1 = ptr2 = head;
        while (true) {
            if (ptr2->next == NULL || ptr2->next->next == NULL)
                return false;
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
            if (ptr1 == ptr2)
                return true;
        }
    }
};


//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        map<ListNode *, bool> mp;
//        ListNode *curr = head;
//        mp[curr] = true;
//        while (head != NULL) {
//            head = head->next;
//            if (mp.find(head) != mp.end())
//                return true;
//            mp[head] = true;
//        }
//        return false;
//    }
//};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}