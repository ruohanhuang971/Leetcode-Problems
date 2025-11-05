#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a string s containing only digits
    - Return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

    Time: O(N), Space complexity: O(N)
*/

/*
    Intuition:
    - at each position, can either decode one digit (if it's valid) or two digits (if the next two form a valid number between 10 and 26).
*/

int numDecodings(string s) {
    vector<int> dp(s.size() + 1);
    dp[0] = 1;

    for (int i = 0; i < s.size(); i++) {
        // previous one + if (valid 2 digit) {2 before}
        if (s[i] != '0') {  // current isn't 0
            dp[i + 1] += dp[i];

            if (i < s.size() - 1) {
                int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (two >= 10 && two <= 26)  // valid 2 digit number
                    dp[i + 2] += dp[i];
            }
        }
    }

    return dp[s.size()];
}