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

//https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool word = false;
    TrieNode() {}
};

class WordDictionary {
public:
    TrieNode *trie;

    WordDictionary() {
        trie = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* currentNode = trie;

        for (char ch: word) {
            auto search = currentNode->children.find(ch);
            TrieNode* child;
            if (search == currentNode->children.end()) {
                child = new TrieNode();
                currentNode->children[ch] = child;
            } else {
                child = search->second;
            }
            currentNode = child;
        }
        currentNode->word = true;
    }

    bool searchInTrie(string word, int currentIndex, TrieNode* node)
    {

        if(node->word && currentIndex == word.size())
            return true;

        if(currentIndex>= word.size())
            return false;

        bool found = false;
        for(auto it = node->children.begin();it != node->children.end();it++)
        {
            char ch = it->first;
            if(ch == word[currentIndex] || word[currentIndex] == '.')
            {
                bool result = searchInTrie(word, currentIndex+1, it->second);
                if(result)
                {
                    found = true;
                    break;
                }
            }
        }
        if(found)
            return true;
        return false;
    }

    bool search(string word) {
        return searchInTrie(word,0,trie);
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