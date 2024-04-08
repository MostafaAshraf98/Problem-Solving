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

// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         vector<ListNode *> v;
//         while (head != nullptr)
//         {
//             v.push_back(head);
//             head = head->next;
//         }
//         int index = v.size() - n;
//         if (v.size() == 1)
//             return nullptr;
//         else if (index == 0)
//             return v[1];
//         else if (index == v.size() - 1)
//             v[index - 1]
//                 ->next = nullptr;
//         else
//             v[index - 1]->next = v[index]->next;
//         return v[0];
//     }
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *current = head;
        while (current != nullptr)
        {
            size++;
            current = current->next;
        }
        ListNode *previous = head;
        current = head->next;
        int index = size - n;

        if (index == 0)
            return head->next;

        for (int i = 1; i < index; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
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