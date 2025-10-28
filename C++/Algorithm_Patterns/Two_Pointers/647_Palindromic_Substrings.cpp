#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a string s
    - return the number of palindromic substrings in it.

    Time: O(N^2), Space: O(1)
*/

/*
    Intuition:
    - expand around each character in the string to discover palindromes
*/

int countSubstrings(string s) {
    if (s.empty()) return 0;

    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        ans += expand(s, i, i);
        ans += expand(s, i, i + 1);
    }

    return ans + 1;
}

int expand(string s, int start, int end) {
    int num = 0;
    while (start >= 0 && end < s.size() && s[start] == s[end]) {
        // cout << s.substr(start, end) << endl;
        num++;
        start--;
        end++;
    }

    return num;
}