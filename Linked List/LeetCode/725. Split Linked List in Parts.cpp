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

//Accepted 
//Linked List

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int count = 0;
        ListNode *current = head;
        vector<ListNode *> result;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        if (count <= k)
        {
            current = head;
            for (int i = 0; i < k; i++)
            {
                if (i < count)
                {
                    auto temp = current->next;
                    current->next = nullptr;
                    result.push_back(current);
                    current = temp;
                }
                else
                {
                    result.push_back(nullptr);
                }
            }
        }
        else
        {
            int part = count / k;
            int remaining = count % k;
            ListNode *nextPartRoot = head;
            for (int j = 0; j < k; j++)
            {
                ListNode *currentRoot = nextPartRoot;
                current = currentRoot;
                for (int i = 0; i < part; i++)
                {
                    if (i == part - 1 && remaining == 0)
                    {
                        nextPartRoot = current->next;
                        current->next = nullptr;
                    }
                    current = current->next;
                }
                if (remaining > 0)
                {
                    remaining--;
                    nextPartRoot = current->next;
                    current->next = nullptr;
                }
                result.push_back(currentRoot);
            }
        }
        return result;
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