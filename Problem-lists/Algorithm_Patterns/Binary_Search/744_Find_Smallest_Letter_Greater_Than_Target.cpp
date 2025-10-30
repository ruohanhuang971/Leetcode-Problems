#include <iostream>
#include <vector>
using namespace std;

/*
    Given an array of letters that is sorted in non-decreasing order, return the smallest character in letters
    that is lexicographically greater than target.

    If such a character does not exist, return the first character in letters.

    Time: O(logN), Space: O(1)
*/

char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;
    int ans = letters[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] > target) {
            ans = letters[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}