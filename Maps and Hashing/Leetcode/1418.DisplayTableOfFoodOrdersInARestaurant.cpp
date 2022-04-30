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

bool sortvec(const vector<string> &a,
             const vector<string> &b) {
    return (stoi(a[0]) < stoi(b[0]));
}

class Solution {
public:


    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        map<string, map<string, int>> mp;
        set<string> types; // for the types to be unique and sorted alphabetically
        for (vector<string> order:orders) {
            auto it = mp.find(order[1]);
            types.insert(order[2]);
            if (it == mp.end()) // if this table does not exist
            {
                map<string, int> table; // create a new table
                table.insert(make_pair(order[2], 1)); // add this order to this table
                mp.insert(make_pair(order[1], table)); // add this table to the  list of tables
            } else // this table exists and it is saved in the iterator it of pair
            {
                auto it2 = it->second.find(order[2]); // searching if this order was ordered before in this table
                if (it2 == it->second.end()) // if this type of order is not ordered before
                    it->second.insert(make_pair(order[2], 1)); // insert this order in this table
                else
                    it2->second++; // increment count for the same existing order in this table
            }
        }
        vector<vector<string>> final; // this is the final vector that we will return
        vector<string> firstRow; // the first row consists of "Table" and the types of orders ordered alphabetically
        firstRow.push_back("Table");
        for (auto type:types) {
            firstRow.push_back(type);
        }
        final.push_back(firstRow);
        vector<vector<string>> ords; // this is the vector of the orders of each table but we did not add it to final 3alatoul 3alashan ne3melo sort fel a5er
        for (auto table = mp.begin(); table != mp.end(); table++) // loop over tables
        {
            vector<string> tableOrders;
            tableOrders.push_back(table->first); // pushback the table number
            for (int i = 1; i < firstRow.size(); i++) // loop over types
            {
                string type = firstRow[i]; // for this type of food
                auto it = table->second.find(type); // serach if it is ordered in this table
                if (it == table->second.end())// this type is not ordered in this table
                    tableOrders.push_back("0"); // it was not ordered put 0
                else
                    tableOrders.push_back(to_string(it->second)); // if it is ordered put the values
            }
            ords.push_back(tableOrders); // add the orders of this table to the vector
        }
        sort(ords.begin(), ords.end(), sortvec); // sort the vector ascendingly by the table number
        final.insert(final.end(), ords.begin(), ords.end()); // concatenate the 2 vectors
        return final; // return the final vector
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}