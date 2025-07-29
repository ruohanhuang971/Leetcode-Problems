#include <iostream>
#include <vector>
using namespace std;

/*
    Time Complexity: O(n), Space Complexity: O(1)
*/

bool isSubsequence(string s, string t) {
    int curIndex = 0;

    if (s.size() == 0) {
        return true;
    }

    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[curIndex]) {
            curIndex++;
        }
        if (curIndex == s.size()) {
            return true;
        }
    }

    return false;
}