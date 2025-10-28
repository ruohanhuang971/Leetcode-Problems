#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N*M) [N = string len, M = longest word in dictionary], Space complexity: O(N)
*/

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    int n = s.size();

    // Create DP array where dp[i] = true if s[0:i] can be segmented
    // Size is n+1 to handle empty string at dp[0]
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    // Find the maximum length word in dictionary for optimization, only need to check substrings up to this length
    int max_len = 0;
    for (const auto& word : wordDict) {
        max_len = std::max(max_len, static_cast<int>(word.size()));
    }

    for (int i = 1; i <= n; i++) {
        // j = starting position of a potential word, check for word ending at i
        for (int j = i - 1; j >= std::max(i - max_len - 1, 0); j--) {
            // Two conditions must be met:
            // 1. dp[j] = true: string up to position j can be segmented
            // 2. s[j:i] exists in wordDict: substring from j to i is a valid word
            if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}