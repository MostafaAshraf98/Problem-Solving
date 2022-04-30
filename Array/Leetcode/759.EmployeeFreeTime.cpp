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

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

//class Solution {
//public:
//    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
//        vector<vector<Interval *>> FreeTime(schedule.size(), vector<Interval *>(0));
//
//        //Get all the free intervals of the every employee
//        for (int k = 0; k < schedule.size(); k++) {
//            if (schedule[k][0].start > 1)
//                FreeTime[k].push_back(new Interval(1, schedule[k][0].start));
//            for (int i = 1; i < schedule[k].size(); i++) {
//                if (schedule[k][i].start != schedule[k][i - 1].end)
//                    FreeTime[k].push_back((new Interval(schedule[k][i - 1].end, schedule[k][i].start)));
//            }
//            int lastEndTIme = schedule[k][schedule[k].size() - 1].end;
//            FreeTime[k].push_back(new Interval(lastEndTIme, INT_MAX));
//        }
//        // Now we have all the free times of all the employees
//        // We need to find the common ones
//        vector<Interval *> commonFreeTime;
//        // Initially the commonFreeTime is the time of the first employee now we should see if it is also common for the other employees
//        for (int i = 0; i < FreeTime[0].size(); i++)
//            commonFreeTime.push_back(FreeTime[0][i]);
//
//        //Loop over the employees
//        for (int i = 1; i < FreeTime.size(); i++) {
//            int k = 0; // iterator over the commonFreeTime vector
//            while (commonFreeTime[k] == NULL && k != commonFreeTime.size())
//                k++;
//            //Loop over the free intervals of this employee
//            for (int j = 0; j < FreeTime[i].size(); j++) {
//                if (k == commonFreeTime.size())
//                    break;
//                // There are 4 overlapping possibilities
//                // Then 2 cases of non-overlapping
//                if (commonFreeTime[k]->start < FreeTime[i][j]->start &&
//                    commonFreeTime[k]->end > FreeTime[i][j]->start) {
//                    commonFreeTime[k]->start = FreeTime[i][j]->start;
//                } else if (commonFreeTime[k]->start < FreeTime[i][j]->end &&
//                           commonFreeTime[k]->end > FreeTime[i][j]->end)
//                    commonFreeTime[k]->end = FreeTime[i][j]->end;
//                else if (commonFreeTime[k]->start >= FreeTime[i][j]->start &&
//                         commonFreeTime[k]->end <= FreeTime[i][j]->end) {
//                    //do nothing
//                } else if (commonFreeTime[k]->start <= FreeTime[i][j]->start &&
//                           commonFreeTime[k]->end >= FreeTime[i][j]->end) {
//                    commonFreeTime[k]->start = FreeTime[i][j]->start;
//                    commonFreeTime[k]->end = FreeTime[i][j]->end;
//                } else if (commonFreeTime[k]->end <= FreeTime[i][j]->start) // Non-overlapping and passed
//                {
//                    commonFreeTime[k] = NULL;
//                } else  // non-overlapping but still comming
//                {
//                    //do nothing
//                    continue;
//                }
//                k++;
//                while (commonFreeTime[k] == NULL && k != commonFreeTime.size())
//                    k++;
//            }
//        }
//        vector<Interval> finalResult;
//        for (int i = 0; i < commonFreeTime.size(); i++)
//            if (commonFreeTime[i] != NULL && commonFreeTime[i]->end != INT_MAX) {
//                Interval v(commonFreeTime[i]->start, commonFreeTime[i]->end);
//                finalResult.push_back(v);
//            }
//        return finalResult;
//    }
//};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> mergedWorkInterval;
        for (auto employee: schedule)
            for (auto interval: employee) {
                int start = interval.start;
                int end = interval.end;
                if (mergedWorkInterval.find(start) == mergedWorkInterval.end())//it does not exist
                    mergedWorkInterval[start] = end;
                else
                    mergedWorkInterval[start] = max(mergedWorkInterval[start], end);
            }
        vector<Interval> result;
        // The start and end of the previous working interval
        int prev_start = mergedWorkInterval.begin()->first;
        int prev_end = mergedWorkInterval.begin()->second;
        for (auto[start, end]: mergedWorkInterval) {
            if (start <= prev_end)
                prev_end = max(prev_end, end);
            else {
                result.push_back(Interval(prev_end, start));
                prev_start = start;
                prev_end = end;
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    vector<vector<Interval>> v(3, vector<Interval>(0));
    Interval E11(1, 2);
    v[0].push_back(E11);
    Interval E12(5, 6);
    v[0].push_back(E12);

    Interval E21(1, 3);
    v[1].push_back(E21);

    Interval E31(4, 10);
    v[2].push_back(E31);
    Solution s;
    s.employeeFreeTime(v);

    return 0;
}