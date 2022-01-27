#include <bits/stdc++.h>

using namespace std;

// Note: you won't need long long in this problem

int solve(vector<int> &L, int i, int j, vector<vector<int>> &memo) {
//state:
//L the array of required cut locations
//i: the index eli el current train bade2 fih
//j: the index eli el current train beye5las fih
//memo: the dp memorization array
    // TODO: check if you solved the problem before (memoization) (add this part after you implement the whole function)
    if (memo[i][j] != -1)
        return memo[i][j];
    // TODO: step 2: add base case
    if (j - i == 1) // there are no more cuts
        return memo[i][j] = 0;

    int minLength = INT_MAX;
    // TODO: step 1: write the optimal structure for the solution using subproblems to get the minimum total cost
    for (int start = i + 1; start < j; start++) {
        int temp = solve(L, i, start, memo) + solve(L, start, j, memo);
        if (temp < minLength)
            minLength = temp;
    }

    // TODO: save the minimum total cost in memo (add this part after you implement the whole function)
    memo[i][j] = (L[j] - L[i]) + minLength;
    // TODO: return the minimum total cost
    return memo[i][j];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int N, M;
    cin >> N >> M;

    vector<int> L(M);

    for (int i = 0; i < M; i++) {
        cin >> L[i];
    }

    // TODO: uncomment the following if they help you solve the problem
    L.insert(L.begin(), 0);
    L.push_back(N);

    // TODO: declare DP storage and call it memo
    vector<vector<int>> memo(L.size(), vector<int>(L.size(), -1));

    // This function call is for guidance and you can change it if you want
    cout << solve(L, 0, L.size() - 1, memo) << endl;

    return 0;
}