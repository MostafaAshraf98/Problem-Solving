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

void
traverseTree(vi &levelsSum, vi &levelsMin, const vi &v, const vii &tree, int currentIndex,
             int currentLevel, int &maxLevel) {
    //state:
    //levels: 2D array of levels each level with all the values in it
    //v: the vector of data
    //tree: the current tree
    //currentNode: iterator of the currentNode, it holds its index in the data vector, its right child and its left child
    //currentLevel: the level we are at in this state
    //maxLevel: which represents the heigh
    if (tree[currentIndex].first == -1 && tree[currentIndex].second == -1) // a leaf
    {
        if (currentLevel > maxLevel) // if its height is greater than previous heights
            maxLevel = currentLevel;
        levelsSum[currentLevel] += v[currentIndex];
        if (levelsMin[currentLevel] == -1 || v[currentIndex] < levelsMin[currentLevel])
            levelsMin[currentLevel] = v[currentIndex];
        return;
    }
    levelsSum[currentLevel] += v[currentIndex];
    if (levelsMin[currentLevel] == -1 || v[currentIndex] < levelsMin[currentLevel])
        levelsMin[currentLevel] = v[currentIndex];

    int leftChild = tree[currentIndex].first;
    if (leftChild != -1)
        traverseTree(levelsSum, levelsMin, v, tree, leftChild, currentLevel + 1, maxLevel);

    int rightChild = tree[currentIndex].second;
    if (rightChild != -1)
        traverseTree(levelsSum, levelsMin, v, tree, rightChild, currentLevel + 1, maxLevel);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
//#endif
    int n; // the number of nodes in the tree
    scanf("%d", &n);
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
    //The data is in the vector v and the tree itself is in the map
    //the selected leels start at level 0
    //continues down the tree by k steps every time
    //L = value of root % tree height
    //K = min(Lth level) % tree height
    vi levelsSum(n, 0); // sum every level
    vi levelsMin(n, -1);
    int maxlevel = 0;

    traverseTree(levelsSum, levelsMin, v, tree, 0, 0, maxlevel);

    int height = maxlevel + 1;
    int valueRoot = v[0];
    int L = valueRoot % height;

    int minLthLevelValue = levelsMin[L];

    int K = minLthLevelValue % height;
    string finalResult = "";
    int currentLevel = 0;
    if (K == 0)
        K = 1;
    while (currentLevel <= maxlevel) {
        finalResult += to_string(levelsSum[currentLevel]);
        currentLevel += K;
    }
    cout << finalResult << endl;
    return 0;
}