#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//returns the index in the array H
int HashingFunction(string s) {
    int size = s.size();
    int index;
    switch (size) {
        case 1:
            index = 39 * (int) (s[0]);
            break;
        case 2:
            index = 39 * (int) (s[0]) + 392 * (int) (s[1]);
            break;
        case 3:
            index = 39 * (int) (s[0]) + 392 * (int) (s[1]) + 393 * (int) (s[2]);
            break;
        default:
            index = 39 * (int) (s[0]) + 392 * (int) (s[1]) + 393 * (int) (s[2]) + 394 * (int) (s[3]);
            break;
    }
    return (index % 24000);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("words20K.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
#endif
    string A[20000];
    for (int i = 0; i < 20000; i++)
        cin >> A[i];
    string H[24000];
    for (int i = 0; i < 24000; i++)
        H[i] = "";
    vector<double> AverageInsertionTime; // holds insertion times for every batch of 500 words
    auto startTime = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20000; i++) {
        string x = A[i];
        int index = HashingFunction(x);
        while (H[index] != "") {
            index++;
            index = index % 24000;
        }
        H[index] = x; // insert
        if ((i + 1) % 500 == 0)// we inserted 500 words, calculate time
        {
            auto endTime = chrono::high_resolution_clock::now();
            auto time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
            double durationInMilli = time.count();
            double average = durationInMilli / 500.0;
            AverageInsertionTime.push_back(average);
            startTime = chrono::high_resolution_clock::now();
        }
    }

    //search and delete requirement
    //The following code is based on the givens that all the data is unique and we are sure that the data is inserted
    int minProbes = -1;
    int maxProbes = -1;
    int sumProbes = 0;
    int averageProbes;
    for (int i = 14000; i < 15000; i++) {
        string x = A[i];
        int index = HashingFunction(x);
        int count = 0;
        if (H[index] == x) // it exists in this location
        {
            H[index] = "-1"; // delete it
        } else {
            index++;
            index = index % 24000;
            count++; //counting the number of probes
            while (H[index] != x) {
                index++;
                index = index % 24000;
                count++;
            }
            H[index] = "-1";
        }
        sumProbes += count;
        if (minProbes == -1 || count < minProbes)
            minProbes = count;
        if (maxProbes == -1 || count > maxProbes)
            maxProbes = count;
    }
    averageProbes = sumProbes / 1000;

    cout << "The average Time in milliseconds for insertion each 500 are:" << endl;
    for (int i = 0; i < AverageInsertionTime.size(); i++) {
        cout << AverageInsertionTime[i];
        cout << endl;
    }
    cout << " min number of probes across 1000 searches: " << minProbes << endl;
    cout << " max number of probes across 1000 searches: " << maxProbes << endl;
    cout << " average number of probes across 1000 searches: " << averageProbes << endl;

    return 0;
}