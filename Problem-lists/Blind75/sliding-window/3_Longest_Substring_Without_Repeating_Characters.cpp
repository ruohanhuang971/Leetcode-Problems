#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    Time: O(N) [Hash map count/insert/erase are O(1) average, Space: O(N) [worst case all character are unqiue]
*/

int lengthOfLongestSubstring(string s) {
    unordered_set<int> seq;
    int start = 0;
    int max_len = 0;
    int cur_len = 0;
    for (auto n : s) {
        if (seq.count(n) == 0) {  // not duplicate character
            seq.insert(n);
            cur_len++;
        } else {
            while (s[start] != n) {
                seq.erase(s[start]);
                cur_len--;
                start++;
            }
            start++;
        }
        max_len = max(max_len, cur_len);
    }

    return max_len;
}