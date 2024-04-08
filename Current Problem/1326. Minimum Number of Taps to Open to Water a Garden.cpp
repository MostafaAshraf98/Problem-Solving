#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)
#define sfs(s) scanf("%s", s)

#define pf(n) printf("%d", n)
#define pff(n, m) printf("%d %d", n, m)
#define pfl(n) printf("%I64d", n)
#define pffl(n, m) printf("%I64d %I64d", n, m)
#define pfs(s) printf("%s", s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int)10e4;

class Solution
{
public:
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.first < p2.first)
            return true;
        else if (p1.first == p2.first)
            return p1.second - p1.first >= p2.second - p2.first;
        else
            return false;
    }

    int minTaps(int n, vector<int> &ranges)
    {
        vector<pair<int, int>> intervals;

        for (int i = 0; i <= n; i++)
        {
            if (ranges[i] == 0)
                continue;
            intervals.push_back({max(0, i - ranges[i]), i + ranges[i]});
        }
        if (intervals.size() == 0)
            return -1;

        sort(intervals.begin(), intervals.end(), cmp);

        int right = intervals[0].second;
        int maxRight = right;
        int count = 1;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (right >= n)
                break;

            if (intervals[i].first <= right)
            {
                maxRight = max(maxRight, intervals[i].second);
                continue;
            }

            if (maxRight < intervals[i].first)
                return -1;

            count++;
            right = maxRight;
            maxRight = max(maxRight, intervals[i].second);
        }
        if (maxRight != right && right < n)
            count++;

        right = maxRight;
        if (right < n)
            return -1;

        return count;
    }
};

// This is a greedy problem.
// First we put in a vector all the gardening intervals and we ignore the zeros because zero just a point and we want to cover all the garden
// so if each tap water its plant then the area between the plants will not be watered.
// we sort the vector from the left end and if there are 2 equal left end we take the one  with the greater interval.
// intially we take the first tap that water from 0 , we should have added a check that the first one has left = 0, if not return -1
// Assuming that it has left = 0 then it is the one with the greatest right.
// the next tap that we need to choose must overlap with this one. so the condition (intervals[i].first<=right)
// we save maxRight (greedy) of all the overlapping taps because it is the one that will choose to take.
// after we reach intervals[i].first> right then we have the first tap that is not overlapping and we will now choose the max overlapping tap
// if the max does not have right greater than or equal this tap then it will not cover it and return -1;
// if it is then we take the current right equal the right of this overlapping tap that we chose to take and the maxRight is the right of it or of this current
// new tap.
// after we exit the for loop we may have not counted the last overlapping tap so we check if the right did not cover the whole garden and 
// they are not equal then we count it. 
// if we do not cover the whole garden then we return -1;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}