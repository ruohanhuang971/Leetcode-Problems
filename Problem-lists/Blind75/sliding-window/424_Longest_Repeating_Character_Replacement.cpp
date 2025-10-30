#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<int, int> count;
    if (s == "") return 0;
    int left = 0;
    int maxCharCount = 0;
    int maxCount = 0;
    int windowSize = 0;

    for (int right = 0; right < s.size(); right++) {
        count[s[right]]++;  // update count of characters in window

        windowSize = right - left + 1;
        maxCharCount = max(maxCharCount, count[s[right]]);

        if (right - left + 1 - maxCharCount > k) {
            count[s[left]]--;  // update count of characters out of window
            left++;            // move window
            windowSize = right - left + 1;
        }

        maxCount = max(maxCount, windowSize);
    }

    return maxCount;
}