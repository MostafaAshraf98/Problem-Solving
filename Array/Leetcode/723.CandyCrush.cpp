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

//https://leetcode.com/problems/candy-crush/

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();
        bool stable = false;
        while (!stable) {
            //scanning the rows and setting the flags for scrushed candies
            for (int i = 0; i < n; i++) {
                int startingIndex = 0;
                int currentValue = abs(board[i][0]);
                for (int j = 1; j < m; j++) {
                    if (abs(board[i][j]) == currentValue) // it has same the value as the one to its left
                        continue;
                    else //it does not have the same value as the one on its left
                    {
                        //check if it is a sequence of 3 or more
                        if (j - startingIndex >= 3) // it is a seq of more than 3
                        {
                            //flag them
                            for (int k = startingIndex; k < j; k++)
                                board[i][k] = -1 * abs(board[i][k]);
                        }
                        //in all cases start a new sequence
                        startingIndex = j;
                        currentValue = abs(board[i][j]);
                    }
                }
                //check again for the last formed sequence
                if (m - startingIndex >= 3) // it is a seq of more than 3
                {
                    //flag them
                    for (int k = startingIndex; k < m; k++)
                        board[i][k] = -1 * abs(board[i][k]);
                }
            }

            //scanning the columns and setting flags for the crushed candies
            for (int j = 0; j < m; j++) {
                int startingIndex = 0;
                int currentValue = abs(board[0][j]);
                for (int i = 1; i < n; i++) {
                    if (abs(board[i][j]) == currentValue) // it has same the value as the one to its left
                        continue;
                    else //it does not have the same value as the one on its left
                    {
                        //check if it is a sequence of 3 or more
                        if (i - startingIndex >= 3) // it is a seq of more than 3
                        {
                            //flag them
                            for (int k = startingIndex; k < i; k++)
                                board[k][j] = -1 * abs(board[k][j]);
                        }
                        //in all cases start a new sequence
                        startingIndex = i;
                        currentValue = abs(board[i][j]);
                    }
                }
                //check again for the last formed sequence
                if (n - startingIndex >= 3) // it is a seq of more than 3
                {
                    //flag them
                    for (int k = startingIndex; k < n; k++)
                        board[k][j] = -1 * abs(board[k][j]);
                }
            }


            //set the flagged candies with 0s
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    board[i][j] = board[i][j] <= 0 ? 0 : board[i][j];


            bool noCandyMoved = true;
            //Apply gravity
            for (int j = 0; j < m; j++) {
                int reader = n - 1;
                int writer = n - 1;
                while (reader != -1) {
                    if (board[reader][j] != 0) // if it has candy
                    {
                        board[writer][j] = board[reader][j];
                        if (reader != writer) // dropped due to gravity
                        {
                            noCandyMoved = false;
                            board[reader][j] = 0;
                        }
                        writer--;
                        reader--;
                        continue;
                    }
                    reader--;
                }
            }

            //if No candies moved at all --> stable is true
            if (noCandyMoved)
                stable = true;
        }
        return board;
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