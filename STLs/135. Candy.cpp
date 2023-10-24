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
    int candy(vector<int> &ratings)
    {
        const int INCREASING = 1;
        const int DECREASING = -1;
        const int CONSTANT = 0;
        const int VALLEY = -2;
        const int PEAK = 2;
        vector<int> candies(ratings.size(), 0);
        int rem = ratings.size();
        int result = 0;

        vector<int> state(ratings.size(), 0);
        if (ratings.size() == 0)
            return 0;
        else if (ratings.size() == 1)
            return 1;

        if (ratings[0] > ratings[1])
            state[0] = PEAK;
        else if (ratings[0] < ratings[1])
        {
            state[0] = VALLEY;
            candies[0] = 1;
            result++;
            rem--;
        }
        else
        {
            state[0] = CONSTANT;
            candies[0] = 1;
            result++;
            rem--;
        }

        if (ratings[ratings.size() - 1] > ratings[ratings.size() - 2])
            state[ratings.size() - 1] = PEAK;
        else if (ratings[ratings.size() - 1] < ratings[ratings.size() - 2])
        {
            state[ratings.size() - 1] = VALLEY;
            candies[ratings.size() - 1] = 1;
            result++;
            rem--;
        }
        else
        {
            state[ratings.size() - 1] = CONSTANT;
            candies[ratings.size() - 1] = 1;
            result++;
            rem--;
        }

        for (int i = 1; i < ratings.size() - 1; i++)
        {
            if (ratings[i] == ratings[i - 1] && ratings[i] == ratings[i + 1])
            {
                state[i] = CONSTANT;
                candies[i] = 1;
                result++;
                rem--;
            }
            else if (ratings[i] > ratings[i - 1] && ratings[i] <= ratings[i + 1])
                state[i] = INCREASING;
            else if (ratings[i] <= ratings[i - 1] && ratings[i] > ratings[i + 1])
                state[i] = DECREASING;
            else if (ratings[i] >= ratings[i - 1] && ratings[i] >= ratings[i + 1])
                state[i] = PEAK;
            else
            {
                state[i] = VALLEY;
                candies[i] = 1;
                result++;
                rem--;
            }
        }
        while (rem != 0)
        {
            for (int i = 0; i < ratings.size(); i++)
            {
                if (candies[i] != 0)
                    continue;

                if (state[i] == INCREASING && candies[i - 1] != 0)
                {
                    candies[i] = candies[i - 1] + 1;
                    result += candies[i];
                    rem--;
                }
                else if (state[i] == DECREASING && candies[i + 1] != 0)
                {
                    candies[i] = candies[i + 1] + 1;
                    result += candies[i];
                    rem--;
                }
                else if (state[i] == PEAK)
                {
                    if (i == 0)
                    {
                        if (candies[i + 1] != 0)
                        {
                            candies[i] = candies[i + 1] + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                    else if (i == ratings.size() - 1)
                    {
                        if (candies[i - 1] != 0)
                        {
                            candies[i] = candies[i - 1] + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                    else
                    {
                        if (candies[i - 1] != 0 && candies[i + 1] != 0)
                        {
                            candies[i] = max(candies[i - 1], candies[i + 1]) + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                }
            }
            for (int i = ratings.size() - 1; i >= 0; i--)
            {
                if (candies[i] != 0)
                    continue;

                if (state[i] == INCREASING && candies[i - 1] != 0)
                {
                    candies[i] = candies[i - 1] + 1;
                    result += candies[i];
                    rem--;
                }
                else if (state[i] == DECREASING && candies[i + 1] != 0)
                {
                    candies[i] = candies[i + 1] + 1;
                    result += candies[i];
                    rem--;
                }
                else if (state[i] == PEAK)
                {
                    if (i == 0)
                    {
                        if (candies[i + 1] != 0)
                        {
                            candies[i] = candies[i + 1] + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                    else if (i == ratings.size() - 1)
                    {
                        if (candies[i - 1] != 0)
                        {
                            candies[i] = candies[i - 1] + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                    else
                    {
                        if (candies[i - 1] != 0 && candies[i + 1] != 0)
                        {
                            candies[i] = max(candies[i - 1], candies[i + 1]) + 1;
                            result += candies[i];
                            rem--;
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}