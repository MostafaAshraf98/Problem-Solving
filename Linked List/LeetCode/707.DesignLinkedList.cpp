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

class Node {
public:
    int val;
    Node *next;
};

class MyLinkedList {
public:
    Node *head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node *current = head;
        if (head == NULL)
            return -1;
        for (int i = 0; i < index; i++) {
            if (current->next == NULL)
                return -1;
            current = current->next;
        }

        return current->val;

    }

    void addAtHead(int val) {
        Node *n = new Node();
        n->val = val;
        n->next = head;
        head = n;

    }

    void addAtTail(int val) {
        if (head == NULL) {
            this->addAtHead(val);
            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        Node *n = new Node();
        n->val = val;
        n->next = NULL;
        curr->next = n;

    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        if (head == NULL)
            return;
        Node *prev = head;
        Node *curr = head->next;
        for (int i = 1; i < index; i++) {
            if (curr == NULL)
                return;
            curr = curr->next;
            prev = prev->next;
        }
        Node *n = new Node();
        n->val = val;
        n->next = curr;
        prev->next = n;
        return;
    }

    void deleteAtIndex(int index) {
        if (head == NULL)
            return;
        if (index == 0) {
            head = head->next;
            return;
        }
        Node *prev = head;
        Node *curr = head->next;
        for (int i = 1; i < index; i++) {
            if (curr->next == NULL)
                return;
            curr = curr->next;
            prev = prev->next;
        }
        if (curr != NULL)
            prev->next = curr->next;
        else
            prev->next = NULL;
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    MyLinkedList *obj = new MyLinkedList();
//    obj->addAtHead(1);
//    obj->addAtTail(3);
//    obj->addAtIndex(1, 2);
//    cout << obj->get(1);
//    obj->deleteAtIndex(1);
//    cout << obj->get(1);

//    obj->addAtHead(1);
//    obj->deleteAtIndex(0);

//    obj->addAtHead(7);
//    obj->addAtHead(2);
//    obj->addAtHead(1);
//    obj->addAtIndex(3, 0);
//    obj->deleteAtIndex((2));
//    obj->addAtHead(6);
//    obj->addAtTail(4);
//    obj->get(4);
//    obj->addAtHead(4);
//    obj->addAtIndex(5, 0);
//    obj->addAtHead(6);

//obj->addAtHead(2);
//obj->addAtIndex(0,1);
//cout << obj->get(1) <<endl;

    obj->addAtTail(1);
    obj->addAtTail(3);
    obj->get(1);

    return 0;
}