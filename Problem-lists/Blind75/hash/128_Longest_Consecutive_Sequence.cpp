#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    The problem specifiy asks for O(N) time, so have to use unordered_set:
        - set need O(NlongN) to insert all the memebers
        - priority_queue queue need O(NlogN) to pop all the memebers since pops take O(logN)
*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for (auto n : nums) {
        hash.insert(n);
    }

    int count = 0;
    int maxCount = 0;
    for (auto n : hash) {
        if (hash.count(n - 1) == 0) {  // if is not in a consequtive sequence
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