#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a string s and an integer k
    - Choose any character of the string and change it to any other uppercase English character up to most k times.
    - Return the length of the longest substring containing the same letter you can get after performing the above operations.
    Time: O(N), Space: O(1)
*/

/*
    Note:
    - Use two pointers for the sliding window.
    - Maintain a frequency array freq(26) for characters.
    - Track the maximum frequency maxf of any character in the current window.
    - If (window size - maxf) > k, shrink the window from the left.
    - Update the maximum length of a valid window.
*/

int characterReplacement(string s, int k) {
    int start = 0;
    int end = 0;

    vector<int> freq(26);
    int maxf = 0;
    int maxLen = 0;
    while (end < s.size()) {
        freq[s[end] - 'A']++;  // add to freqency
        maxf = max(maxf, freq[s[end] - 'A']);

        // If (window size - maxf) > k, shrink the window from the left.
        if ((end - start + 1) - maxf > k) {
            freq[s[start] - 'A']--;
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
        end++;
    }

    return maxLen;
}