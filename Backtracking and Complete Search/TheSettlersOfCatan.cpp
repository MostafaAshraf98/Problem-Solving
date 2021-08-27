#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=480
//ACCEPTED

int isUsedEdge[25]; // visited nodes
vii edges;
int longest = 0;
int Count = 0;
int n; // number of nodes
int m; // number of edges

bool isValidEdge(int currentNode, int edge) {
    if (edges[edge].first == currentNode || edges[edge].second == currentNode)
        return true;
    return false;
}

bool noValidEdges(int currentNode) {
    for (int i = 0; i < m; i++) // loop over all the existing edges
    {
        if ((edges[i].first == currentNode && isUsedEdge[i] == 0) ||
            (edges[i].second == currentNode && isUsedEdge[i] == 0))
            return false;
    }
    return true;
}

void solve(int currentNode) // the position of the current node
{
    if (noValidEdges(currentNode)) {
        if (Count > longest)
            longest = Count;
        return;
    }
    for (int i = 0; i < m; i++) // looping over all edges and see which one we can use
    {
        if (!isValidEdge(currentNode, i) || isUsedEdge[i]) // if this node is already visited
            continue;
        //do
        Count++;
        isUsedEdge[i] = 1;
        //recurse
        if (edges[i].first == currentNode)
            solve(edges[i].second);
        else
            solve(edges[i].first);
        //undo
        Count--;
        isUsedEdge[i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    while (cin >> n && cin >> m && (m != 0 && n != 0)) {
        longest = 0;
        edges.clear();
        for (int i = 0; i < m; i++) // m lines describing the number of edges
        {
            int x, y;
            cin >> x >> y;
            edges.push_back(make_pair(x, y));
        }
        for (int i = 0; i < n; i++) {
            Count = 0;
            memset(isUsedEdge, 0, 26);
            solve(i);
        }
        cout << longest << endl;
    }
    return 0;
}
// Fekret el mas2ala eni banadi el solve bel current node ... 3amelha f for loop 3alashan ana momken abda2 men ay node fihom
// delwa2ti ana ebtadeti men node mo3ayana, hashouf hal fih ay edges betwasal el node di b node tani wala la2 w lazem el edge da maykonsh osta5dam abl keda
// law fih fa ana ba loop over all edges, for each valid edge ( which means the edge wa7da men el etnin no2at betou3o heya el current node w kaman en el edge da ma osta5demsh abl keda)
// do recurse undo --> el do enak te2oul ana esta5demt el edge da w eni zawedt el count wa7ed ... ba - recurse b eni a2oul en el current node heya el node eli el edge da beywasal liha
// el undo eni a2alel el count w eni a2oul en el edge da ana ma esta5demthoush
// leih aslun el for loop ? 3alashan fih kaza valid option f kol (state/transition) fa enta bete3mel do/recurse/undo for each valid option  ( w bema en fih multiple valid options fa ana e7tagt el loop)