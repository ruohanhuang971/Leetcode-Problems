/*
    Prompt: You are given a 0-indexed array of strings words and a character x.
    Return an array of indices representing the words that contain the character x.
    Note that the returned array may be in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    Time complexity: O(n*m)
    Space complexity: O(1)
*/

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> ans;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] == x) {
                ans.push_back(i);
                break;
            }
        }
    }

    return ans;
}

void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << "\n";
}

int main() {
    vector<string> words = {"abc","bcd","aaaa","cbc"};
    char x = 'a';

    vector<int> ans = findWordsContaining(words, x);
    printArray(ans);
}