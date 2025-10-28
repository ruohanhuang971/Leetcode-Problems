#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    - Given a string s
    - Return the length of the longest substring without duplicate characters.
    Time: O(N), Space: O(n)
*/

/*
    Note:
    - sliding window keep track of what is currently considered as subarray
    - set make sure no element is repeating
*/

int lengthOfLongestSubstring(string s) {
    int left = 0;
    int right = 0;

    int maxCount = 0;
    unordered_set<char> st;
    while (left < s.size() && right < s.size()) {
        // not in pattern
        if (st.count(s[right]) == 0) {
            maxCount = max(maxCount, right - left + 1);
        } else {
            while (st.count(s[right]) > 0) {
                st.erase(s[left]);
                left++;
            }
        }
        st.insert(s[right]);
        right++;
    }

    return maxCount;
}