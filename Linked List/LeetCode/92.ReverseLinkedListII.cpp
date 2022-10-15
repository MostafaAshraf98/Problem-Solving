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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        vector<ListNode *> v(501);
        ListNode *temp = head;
        int k = 1;
        while (temp != NULL) {
            v[k] = temp;
            temp = temp->next;
            k++;
        }
        int x = ceil((right - left) / 2.0);
        for (int i = 0; i < x; i++) {
            ListNode *temp2 = v[left + i];
            v[left + i] = v[right - i];
            v[right - i] = temp2;
        }
        v[k] = NULL;
        ListNode *answer = v[1];
        for (int i = 2; i <= k; i++) {
            answer->next = v[i];
            answer = answer->next;
        }
        return v[1];
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