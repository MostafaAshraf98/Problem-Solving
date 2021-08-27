#include <iostream>
#pragma warning(disable : 4996)
#define endl '\n'
using namespace std;
typedef long long ll;
#include <algorithm>
#include <vector>

//https://codeforces.com/problemset/problem/597/B
//ACCEPTED

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        pair <ll, ll> p;
        cin >> p.first >> p.second;
        v.push_back(p);

    }
    sort(v.begin(), v.end(),sortbysec);
    int i = -1;
    int currentTime = -1;
    bool found = true;
    int count = 0;
    do // sha8al tool ma bala2i 7aga ba3d el current time
    {
        found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j].first > currentTime) // bagib awel wa7da ba3d el current time w aktar wa7da bet5alas badri
            {
                currentTime = v[j].second;
                found = true;
                i = j;
                count++;
                break;
            }
        }
    } while (found);

    cout << count << endl;
    return 0;
}

// fekret el mas2ala eni 3andi restaurant w fih rentals , kol rental offer lih start w end
// w mayenfa3sh el start of one rental be the end of the previous one
// fa ana babtedi a3mel sort lel rental offers bel finish time
// ba3d keda ba5od awel offer yekoun badi ba3d el current time fa bel tali ana mota2aked eno haykoun aktar wa7ed beye5las badri
// this gives us the maximum number of rentals