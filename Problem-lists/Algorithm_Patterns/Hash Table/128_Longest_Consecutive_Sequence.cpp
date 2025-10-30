#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    - Given an unsorted array of integers nums
    - Return the length of the longest consecutive elements sequence.
    Time: O(N), Space: O(N)
*/

/*
    Note:
    - put all numbers into unordered_set -> check membership in O(1) time
    - for each number:
        - only start counting if it’s the beginning of a sequence
    - this is O(n) time because it skips all # that isn't the start => only process each number once
*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for (auto n : nums) {
        hash.insert(n);
    }

    int count = 0;
    int maxCount = 0;
    for (auto n : hash) {
        if (hash.count(n - 1) == 0) {  // if is not in a consecutive sequence
            count = 1;
            int temp = n;
            while ((hash.count(temp + 1) > 0)) {
                count++;
                temp++;
            }
            maxCount = max(maxCount, count);
        }
    }

    return max(maxCount, count);
}