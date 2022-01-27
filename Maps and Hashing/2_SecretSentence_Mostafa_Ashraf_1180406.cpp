#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Helper function
void preprocess(string &str) {
    // Removing punctuation
    for (int i = 0, len = str.size(); i < len; i++) {
        // Check whether parsing character is punctuation or not
        if (ispunct(str[i])) {
            str.erase(i--, 1);
            len = str.size();
        }
    }

    // Converting to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Helper function
vector<string> readFile() {
    ifstream f("two-cities.txt"); //taking file as inputstream

    string file;

    if (f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();

        // Removes punctuation and converts to lower case
        preprocess(file);

        // Split into tokens on space
        istringstream iss(file);
        vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};

        return tokens;
    }

    vector<string> empty;
    return empty;
}

// TODO: IMPLEMENT THIS FUNCTION

bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b) {
    return (a.second > b.second);
}

string findSecret(vector<string> tokens) {
    // Hint: you can use std::unordered_map and std::sort
    // unordered_map<string, int>

    string result = "";
    unordered_map<string, int> mp;
    for (int i = 0; i < tokens.size(); i++) {
        string x = tokens[i];
        if (mp.find(x) == mp.end()) // this key is not inserted before
        {
            mp[x] = 1;
        } else {
            mp[x]++;
        }
    }

    vector<pair<string, int>> v;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), sortByVal);

    string word_3 = v[2].first;
    string word_11 = v[10].first;
    string word_22 = v[21].first;
    string word_23 = v[22].first;
    string word_43 = v[42].first;
    string word_47 = v[46].first;

    result = result + " " + word_11 + " " + word_23 + " " + word_22 + " " + word_43 + " " + word_3 + " " + word_47;
    return result;
}

int main() {

    vector<string> tokens = readFile();

    cout << findSecret(tokens) << endl;

    return 0;
}
