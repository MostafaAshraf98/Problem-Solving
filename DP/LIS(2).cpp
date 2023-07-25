#include <bits/stdc++.h>
using namespace std;
int mem[50];
int A[] = {5, 3, 7, 8, 11, 4, 5, 6, 7, 8, 1, 11};

int LIS(int lst)
{
    int &ret = mem[lst];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int prv = 0; prv < lst; prv++)
        if (A[prv] < A[lst])
            ret = max(ret, LIS(prv) + 1);
    return ret;
}
int main()
{
    memset(mem, -1, sizeof mem);
    int mx = 0;
    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); ++i)
        mx = max(mx, LIS(i));
    cout << mx << endl;
}