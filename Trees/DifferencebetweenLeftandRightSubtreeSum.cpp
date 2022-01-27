    #include <bits/stdc++.h>
    #include <stdio.h>

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

    bool check(ll a, ll b, ll r) {
        if (llabs(a - b) <= r)
            return true;
        return false;
    }

    ll traverseTree(const vi &v, const vii &tree, int currentIndex, const int r, int &totalCount) {
        //state:f
        //v: the vector of data
        //tree: the current tree
        //currentNode: iterator of the currentNode, it holds its index in the data vector, its right child and its left child
        //currentLevel: the level we are at in this state
        //maxLevel: which represents the heigh
        //r: is the range for the absolute difference
        int leftChild = tree[currentIndex].first;
        int rightChild = tree[currentIndex].second;

        if (leftChild == -1 && rightChild == -1) // a leaf (there is no left nor right child)
        {
            return v[currentIndex];
        } else if (leftChild != -1 && rightChild != -1) // if there are a left child and right child
        {
            ll countLeft = traverseTree(v, tree, leftChild, r, totalCount);
            ll countRight = traverseTree(v, tree, rightChild, r, totalCount);
            if (check(countLeft, countRight, r))
                totalCount++;
            return v[currentIndex] + countLeft + countRight;
        } else if (leftChild != 1 && rightChild == -1) // there is left child only
        {
            ll countLeft = traverseTree(v, tree, leftChild, r, totalCount);
            if (check(countLeft, 0, r))
                totalCount++;
            return v[currentIndex] + countLeft;

        } else if (leftChild == -1 && rightChild != -1) // there is a right child only
        {
            ll countRight = traverseTree(v, tree, rightChild, r, totalCount);
            if (check(0, countRight, r))
                totalCount++;
            return v[currentIndex] + countRight;
        }

    }

    int main() {
        ios_base::sync_with_stdio(0), cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "rt", stdin);
        freopen("out.txt", "wt", stdout);
    #endif
        int n; // the number of nodes in the tree
        int r;

        scanf("%d", &n);
        scanf("%d", &r);
        vi v(n); // array of data of Nodes
        vii tree(n); // parent index left child index, right child index
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            ii p = make_pair(-1, -1);
            tree[i] = p;
        }
        int e; // the number of edges
        scanf("%d", &e);
        for (int i = 0; i < e; i++) {
            char position;
            int parentIndex;
            int childIndex;
            scanf("%s%d%d", &position, &parentIndex, &childIndex);
            if (position == 'L') {
                tree[parentIndex].first = childIndex;
            } else if (position == 'R') {
                tree[parentIndex].second = childIndex;
            }
        }
        int totalCount = 0;
        traverseTree(v, tree, 0, r, totalCount);
        pf(totalCount);

        return 0;
    }