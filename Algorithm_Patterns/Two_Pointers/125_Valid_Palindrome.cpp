#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a string s, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters
    - return true if it is a palindrome, or false otherwise.

    Time: O(N), Space: O(1)
*/

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Skip non-alphanumeric characters from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}