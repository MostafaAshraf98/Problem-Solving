#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

class MainBST;

class SecondaryBST;

class NodeDep;

class NodeId;


class NodeDep {
public:
    int depKey;
    SecondaryBST *secTree;
    NodeDep *LeftChild;
    NodeDep *RightChild;
    NodeDep *Parent;
public:
    NodeDep() {
        depKey = 0;
        secTree = NULL;
        LeftChild = NULL;
        RightChild = NULL;
        Parent = NULL;
    }
};

class NodeId {
public:
    int id;
    NodeId *LeftChild;
    NodeId *RightChild;
    NodeId *Parent;
public:
    NodeId() {
        id = 0;
        LeftChild = NULL;
        RightChild = NULL;
        Parent = NULL;
    }

};

class SecondaryBST {
public:
    NodeId *Root;

    SecondaryBST() {
        Root = NULL;
    }

    void insertTree(int id) {
        NodeId *n = new NodeId();
        n->id = id;
        NodeId *y = NULL;
        NodeId *x = Root;
        while (x != NULL) {
            y = x;
            if (n->id < x->id)
                x = x->LeftChild;
            else
                x = x->RightChild;

        }
        n->Parent = y;
        if (y == NULL)
            Root = n;
        else if (n->id < y->id)
            y->LeftChild = n;
        else
            y->RightChild = n;
    }

    NodeId *Search(NodeId *x, int id, int &count) {
        if (x != NULL)
            count++;
        if (x == NULL || x->id == id)
            return x;
        if (id < x->id)
            return Search(x->LeftChild, id, count);
        else
            return Search(x->RightChild, id, count);
    }

};


class MainBST {
public:
    NodeDep *Root;
public:
    MainBST() {
        Root = NULL;
    }

    void insertTree(int DepKey, int Id) {
        NodeDep *y = NULL;
        NodeDep *x = Root;
        while (x != NULL) {
            y = x;
            if (DepKey < x->depKey) //less than
                x = x->LeftChild;
            else if (DepKey > x->depKey) // greater
                x = x->RightChild;
            else //equal which means that we found this dep
            {
                //insert the id in this department
                SecondaryBST *sec = x->secTree;
                sec->insertTree(Id);
                return;
            }
        }
        NodeDep *n = new NodeDep();
        n->secTree = new SecondaryBST();
        n->depKey = DepKey;
        //insert new dep and the id in it
        n->Parent = y;
        if (y == NULL)
            Root = n;
        else if (n->depKey < y->depKey)
            y->LeftChild = n;
        else
            y->RightChild = n;
        n->secTree->insertTree(Id);
    }

    NodeId *Search(NodeDep *x, int depKey, int id, int &count) {
        if (x != NULL)
            count++;
        if (x == NULL)
        {
            return NULL;
        }
        else if ( x->depKey == depKey)
        {
            SecondaryBST* sec = x->secTree;
            NodeId* root = sec->Root;
            NodeId* n = sec->Search(root,id,count);
            return n;
        }
        if (depKey < x->depKey)
            return Search(x->LeftChild, depKey, id, count);
        else
            return Search(x->RightChild, depKey, id, count);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int N; //the number of entries
    int Q; // the number of queries
    cin >> N >> Q;

    //Enter N entries
    MainBST *tree = new MainBST();
    for (int i = 0; i < N; i++) {
        int depKey, id;
        cin >> depKey >> id;
        tree->insertTree(depKey, id);
    }
    //enter the query and execute it
    for (int i = 0; i < Q; i++) {
        int depKey, id;
        cin >> depKey >> id;
        int count = 0;
        NodeId *dep = tree->Search(tree->Root, depKey, id, count);
        if (dep == NULL) {
            cout << count << " 0" << endl;
        } else {
            cout << count << " 1" << endl;
        }

    }
    return 0;
}