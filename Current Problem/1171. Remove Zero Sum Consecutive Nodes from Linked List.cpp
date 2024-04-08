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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *ptr1 = nullptr;
        ListNode *ptr2 = head;
        int sum = 0;
        while (true)
        {
            sum += ptr2->val;
            if (sum == 0)
            {
                if (ptr1 == nullptr)
                    head = ptr2->next;
                else
                    ptr1->next = ptr2->next;
                ptr1 = nullptr;
                ptr2 = head;
            }
            else
            {
                ptr2 = ptr2->next;
                if (ptr2 == nullptr)
                {
                    if (ptr1 == nullptr)
                        ptr1 = head;
                    else
                        ptr1 = ptr1->next;
                    ptr2 = ptr1->next;
                    sum = 0;
                }
            }
            if (ptr2 == nullptr)
                break;
        }
        return head;
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