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

//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=655
//ACCEPTED

ll pages [501]; // array of pages in every book
bool isFinalBook[501]; // keeps track of the final book assigned to each scriber



int m,k;
bool valid(int maxNumPages)
{
    //maxNumPages is the maximum number of pages assigned to a single scriber
    ll pagesForCurrent=0; // counts the number of pages assigned the current scriber
    ll numberUsed=0; // counts the number of used scribers
    for(int book= m-1;book>=0;--book)
        //looping over the books from the last book to the first so that we assign the max to the last scriber and then the one before and so on
    {
        if(pages[book]+ pagesForCurrent>maxNumPages)
            // if we assign that book to the current scriber it will pass the maximum
        {
            numberUsed++; // number of used scribers
            if(numberUsed ==k) // if the all the scribers are used and there still are books
                return false;
            pagesForCurrent = pages[book]; // we assigned this book for the new current scriber
        } else
        {
            pagesForCurrent+=pages[book];
        }
    }
    return true;
}

ll BS(ll sum, ll largest)
//returns the minimum number of pages assigned
{
    ll st =largest, end =sum;
    while(st<end)
    {
        ll mid = st + (end-st)/2;
        if(valid(mid))
            end=mid;
        else
            st=mid+1;
    }
    return st;
}

void breakDownBooks(ll maximumPages)
{
    ll pagesForCurrent=0; // counts the number of pages assigned for the current scriber
    ll currentScriber = k-1;

    for(int book = m-1;book>=0;--book)
    {
        if(pages[book]+pagesForCurrent>maximumPages || // cant do anymore pages
        currentScriber == book+1) // there are as many books as scribers
        {
            --currentScriber;
            isFinalBook[book]=true;
            pagesForCurrent=0;
        }
        pagesForCurrent+=pages[book];
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int t;
    sf(t);
    while (t--)
    {
        sff(m,k);
        ll sum=0;
        ll largest =0;
        for(int i=0;i<m;i++)
        {
            isFinalBook[i]=false;
            sfl(pages[i]);
            sum+=pages[i];
            largest = max(largest,pages[i]);
        }

        ll maxPages = BS(sum,largest);
        breakDownBooks(maxPages);

        pf(pages[0]);
        if(isFinalBook[0])
            pfs(" /");
        for(int i=1;i<m;++i)
        {
            pfs(" ");
            pf(pages[i]);
            if(isFinalBook[i])
                pfs(" /");
        }
        nl;
    }

    return 0;
}