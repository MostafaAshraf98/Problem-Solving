#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//https://codeforces.com/problemset/problem/413/C
//ACCEPTED

bool comp (const int & x,const int & y)
{
    return y<x;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    int n;//the total number of questions
    int m; // the number of auction questions
    cin >> n >> m;
    int ptr1 = 1;
    int ptr2 = 1;
    int questionPoints[N];
    int auctionIndices[N];
    for (int i = 1; i <= n; i++)
        cin >> questionPoints[i];
    for (int i = 1; i <= m; i++)
        cin >> auctionIndices[i];

    sort(auctionIndices,auctionIndices+m+1);
    vi auctionQuestionsPoints;
    ll totalScore=0;
    while (ptr1 != (n+1) || ptr2 != (m+1)) {
        if (auctionIndices[ptr2] == ptr1) // if it is an auction question
        {
            auctionQuestionsPoints.push_back(questionPoints[ptr1]);
            ptr1++;
            ptr2++;
            continue;
        }
        else
        {
            totalScore+=questionPoints[ptr1];
            ptr1++;
        }
    }
    sort(auctionQuestionsPoints.begin(),auctionQuestionsPoints.end(),comp);
    for(int i=0;i<auctionQuestionsPoints.size();i++)
    {
        if(totalScore>auctionQuestionsPoints[i])
            totalScore*=2;
        else
            totalScore+=auctionQuestionsPoints[i];
    }
    cout << totalScore << endl;
    return 0;
}
//ha3od a7ell kol eli mesh auction ba3d keda a5osh 3ala el auction  a5od eli el value beta3ethom akbar el awel
// 3alashan keda keda in case of auction question ... ya ela ha5od el score beta3o ya ela ha3mel el score beta3i x2
// law el score beta3i kan a3la men el points beta3to fa a7sanli a5od el akbar el awel 3alashan lama adraf f 2 yeb2a el rakam akbar