#include <iostream>
#include <vector>
using namespace std;

/*
    - Design a data structure that supports adding new words and finding if a string matches any previously added string.

    Time: O(N*M) [each cell visited once], Space: O(N*M) [worse case all cells are '1' and DFS may go as deep as m × n]
*/

/*
    Note:
    - use a prefix tree structure where each node represent's a single character. And each node could have up to 26 additional children
    - when going down the 'a' branch, all words starting with 'a' are in that branch -> efficient
*/

class WordDictionary {
   public:
    WordDictionary() {
        children = vector<WordDictionary*>(26, nullptr);
    }

    void addWord(string word) {
        WordDictionary* cur = this;
        for (char c : word) {
            int index = c - 'a';
            if (cur->children[index] == nullptr) {
                cur->children[index] = new WordDictionary();
            }
            cur = cur->children[index];
        }
        cur->wordEnd = true;
    }

    bool search(string word) {
        WordDictionary* cur = this;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                // need to look at all children
                for (auto child : cur->children) {
                    if (child && child->search(word.substr(i + 1))) return true;
                }
                return false;
            }
            int index = word[i] - 'a';
            if (cur->children[index] == nullptr) return false;
            cur = cur->children[index];
        }
        return cur && cur->wordEnd;
    }

    vector<WordDictionary*> children;
    bool wordEnd = false;
};