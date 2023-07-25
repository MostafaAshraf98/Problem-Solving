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
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> currentAsteroids;
        for (int asteroid : asteroids)
        {
            if (asteroid > 0)
                currentAsteroids.push_back(asteroid);

            else
            {
                bool isDestroyed = false;
                int size = currentAsteroids.size() - 1;
                for (int i = size; i >= 0; i--)
                {
                    if (currentAsteroids[i] < 0)
                        break;
                        
                    if (abs(asteroid) > currentAsteroids[i])
                    {
                        currentAsteroids.pop_back();
                    }
                    else if (abs(asteroid) == currentAsteroids[i])
                    {
                        isDestroyed = true;
                        currentAsteroids.pop_back();
                        break;
                    }
                    else
                    {
                        isDestroyed = true;
                        break;
                    }
                }
                if (!isDestroyed)
                    currentAsteroids.push_back(asteroid);
            }
        }
        return currentAsteroids;
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