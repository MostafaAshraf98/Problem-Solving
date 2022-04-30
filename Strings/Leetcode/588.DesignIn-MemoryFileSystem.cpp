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

vector<string> splittingString(string given_str) {
    vector<string> result;
    size_t pos = 0;
    string delim = "/";
    while ((pos = given_str.find(delim)) != std::string::npos) {
        string temp = given_str.substr(0, pos);
        if (temp != "")
            result.push_back(temp); // store the substring
        given_str.erase(0,
                        pos + delim.length());  /* erase() function store the current positon and move to next token. */
    }
    if (given_str != "")
        result.push_back(given_str);
    return result;

}

class FileSystem {
public:
    map<string, set<string>> mp; // every path has a list of paths or a content


    FileSystem() {
        set<string> s;
        mp["/"] = s;
    }

    vector<string> ls(string path) {
        vector<string> result;
        vector<string> splittingPath = splittingString(path);
        auto s = mp[path];
        if (s.find("file") != s.end()) // it is a  file
            //return a list that only contains this file name
            result.push_back(splittingPath[splittingPath.size() - 1]);
        else // it is a directory file
        {
            // return the list of file and directory names in this directory
            for (auto f: s)
                result.push_back(f);
        }
        return result;
    }

    void mkdir(string path) {
        vector<string> splittingPath = splittingString(path);
        string constructingPath = "";
        for (auto path: splittingPath) {
            string tempPrev = constructingPath;
            constructingPath += "/" + path;
            if (mp.find(constructingPath) == mp.end()) // if this path does not exist
            {
                if (tempPrev == "")
                    tempPrev = "/";
                //add it to the previous path
                mp[tempPrev].insert(path);
                //add itself
                set<string> s;
                mp[constructingPath] = s;
            }

        }

    }

    void addContentToFile(string filePath, string content) {
        if (mp.find(filePath) != mp.end()) // it exists
        {
            set<string> &s = mp[filePath];
            auto it = mp[filePath].begin();
            if (*it == "file")
                it++;
            string oldContent = *it;
            s.erase(oldContent);
            s.insert(oldContent + content);

            return;
        }
        int end = filePath.size() - 1;
        int count = 0;
        while (filePath[end] != '/') {
            end--;
            count++;
        }
        string dir = filePath.substr(0, filePath.size() - count - 1);
        if (dir == "")
            dir = "/";
        string file = filePath.substr(filePath.size() - count, count);
        mp[dir].insert(file);

        set<string> temp;
        temp.insert("file");
        temp.insert(content);
        mp[filePath] = temp;
    }

    string readContentFromFile(string filePath) {
        auto s = mp[filePath];
        auto it = s.begin();
        if (*it == "file")
            it++;
        return *it;
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