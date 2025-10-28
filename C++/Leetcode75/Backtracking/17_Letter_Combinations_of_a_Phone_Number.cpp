#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(4^N), Space: O(N)
*/

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return vector<string>();
    }

    vector<string> ans;
    helper(digits, 0, ans, "");
    return ans;
}

void helper(string digit, int i, vector<string>& ans, string curCombo) {
    if (digit.size() == i) {  // reached expected length
        ans.push_back(curCombo);
        return;
    }

    vector<string> letter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = digit[i] - '0' - 2;
    for (auto n : letter[index]) {
        string temp = curCombo + n;
        helper(digit, i + 1, ans, temp);
    }
    return;
}