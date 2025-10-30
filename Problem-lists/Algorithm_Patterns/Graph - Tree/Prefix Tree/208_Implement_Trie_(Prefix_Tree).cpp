#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*

*/

/*
    Intuition:
    - Use Prefix tree structure
*/

class Trie {
   public:
    Trie() {
        children = vector<Trie*>(26);
        wordEnd = false;
    }

    void insert(string word) {
        Trie* cur = this;
        for (auto n : word) {
            if (!(cur->children[n - 'a'])) {
                // make new if it doesn't exist yet
                cur->children[n - 'a'] = new Trie();
            }
            cur = cur->children[n - 'a'];
        }
        // mark as end of word for search
        cur->wordEnd = true;
    }

    bool search(string word) {
        Trie* cur = this;
        for (auto n : word) {
            if (!(cur->children[n - 'a'])) {
                return false;
            }
            cur = cur->children[n - 'a'];
        }
        // mark as end of word for search
        return cur->wordEnd == true;
    }

    bool startsWith(string prefix) {
        Trie* cur = this;
        for (auto n : prefix) {
            if (!(cur->children[n - 'a'])) {
                return false;
            }
            cur = cur->children[n - 'a'];
        }
        return true;
    }

    vector<Trie*> children;
    bool wordEnd;
};