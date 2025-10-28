#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given an unsorted array of integers nums
    - Return the length of the longest consecutive elements sequence.
*/

string minWindow(string s, string t) {
    int left = 0, right = 0;
    unordered_map<char, int> need, window;

    for (char c : t) need[c]++;

    int minLen = INT_MAX, minStart = 0;

    while (right < s.size()) {
        char cur = s[right];
        window[cur]++;

        // Try to shrink the window while it's valid
        while (left <= right && allFound(window, need)) {
            // Update the result
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // Shrink the window from the left
            window[s[left]]--;
            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

bool allFound(unordered_map<char, int>& m, unordered_map<char, int>& need) {
    for (auto n : need) {
        if (m[n.first] < n.second) return false;
    }
    return true;
}