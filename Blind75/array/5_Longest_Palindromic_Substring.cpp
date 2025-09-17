#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N^2), Space: O(1)
    Intuition: a palindrome can be mirrored around its center
        - iterate over string and for every center expand around it
        - note: center of a palindrome can be in between two letters. ex: "abba" its center are between the two 'b's.
*/

string longestPalindrome(string s) {
    string cur_str = "";
    string max_str = s.substr(0, 1);
    for (int i = 0; i < s.size() - 1; i++) {
        cur_str = expand(s, i, i);
        if (cur_str.size() > max_str.size()) max_str = cur_str;
        cur_str = expand(s, i, i + 1);
        if (cur_str.size() > max_str.size()) max_str = cur_str;
    }

    return max_str;
}

string expand(string s, int start, int end) {
    int temp = 0;
    int len = 0;
    while (start >= 0 && end < s.size() && s[start] == s[end]) {
        temp = start;
        len = end - start + 1;
        start--;
        end++;
    }

    return s.substr(temp, len);
}