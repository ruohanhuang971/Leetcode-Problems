#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N^2), Space: O(1)
    First method: uses the idea that each palindromic string has a center point
    Second method: optimal method with Manacher's algorithm
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

/*
    Manacher's algorithm:
        - instead of checking every center from scratch [O(n²)], it only visit each character at most twice [once to expand once to check for mirror -> O(n)]
        - If found a large palindrome, positions inside it mirror each other
            - ex: aibioibia
            - since left of "o" = right of "o" therefore: length of palindrome centered at the right "b" == length of palindrome
              centered at left b [because "ibi" is entirely contained by palindrome centered at "o"]
        - If the letter's mirror palindrome is completely contained by the larger palindrome, the palindrome length around the letter is the same as its mirror's palindrome length
        - If the letter's mirror palindrome exists entirely within the larger palindrome up to the border, the current letter's palindrome is at least as long as its mirror's palindrome
        - If the letter's mirror palindrome extends beyond the larger palindrome, then the current letter's palindrome is at least as long as 2 * (distance to right border) + 1
        - If current letter is not contained in the larger palindrome, no info and need to expand around its center

    1. Insert '#' between every character so all ALL palindromes have odd length with a single center
        - odd: "aba" even: "abba" -> odd: "#a#b#a#" odd:"#a#b#b#a#"
    2. dp array store longest palindrome centered at index i
*/
int countSubstrings(string s) {
    int n = s.length();
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    n = t.length();
    vector<int> dp(n, 0);
    int center = 0, right = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            dp[i] = min(right - i, dp[mirror]);
        }
        // Attempt to expand palindrome centered at i
        int a = i + (1 + dp[i]);
        int b = i - (1 + dp[i]);
        while (a < n && b >= 0 && t[a] == t[b]) {
            dp[i]++;
            a++;
            b--;
        }
        // If palindrome centered at i expands past right,
        // adjust center and right boundaries
        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }
        // Count the palindromes found at index i
        count += (dp[i] + 1) / 2;
    }
    return count;
}