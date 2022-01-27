
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    int n; // number of rows
    int m; // number of columns
    int number[500][500]; // the matrix of heights

    while(cin >> n >> m && (n || m))
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                cin >> number[i][j];
        }

        int q; // the number of queries
        cin >> q;

        while(q--)
        {
            int a; // the lower height (greater than or equal)
            int b; // the upper height (less than or equal)
            cin >> a >> b;

            int maxSize = 0; // the result (the largest side of number of properties of a contiguous square area with heights within the interval specified)
            for(int i = 0; i < n; ++i)
            // looping over all the rows
            {
                // lower_bound() returns an iterator pointing to the first element in the range [first, last) which has a value not less than val.
                // NOTE: number[i] is a pointer not a value as number is 2D matrix (an array of arrays
                // so subtracting number[i] gets you the index of the minimun position (as you subtract two addresses
                int minPosition = lower_bound(number[i], number[i] + m, a) - number[i];
                //you get in minposition the first element in the row that is greater than or equal to a (the lower height) which means satisfies the condition

                for(int j = maxSize; j < n; ++j)
                // we start fro the maxsize because we wont waaste our time with results that is worse than the one we already have
                    // j is the length of the side of the current tested square
                {
                    if(n <= i + j or m <= minPosition + j or b < number[i + j][minPosition + j])
                        //now we are looking is b(upper bound)>= number[i+j][minposition+j]
                        //imagine the square having as top left corner number[i][minposition] and bottom right corner number[i+j][minposition+j]
                        // the first two conditions means the this current testing square is out of bounds
                        // the thirs means that the bottom right corner has height higher than the upper bound (b)
                        break;

                    maxSize = max(maxSize, j + 1); // here it is j +1 because for example if j=1 it means that the sqaure has length of 2 and so on
                }

            }

            cout << maxSize << "\n";
        }
        cout << "-\n";
    }

    return 0;
}