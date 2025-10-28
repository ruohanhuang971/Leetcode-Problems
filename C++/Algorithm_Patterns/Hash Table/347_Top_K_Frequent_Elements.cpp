#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given an integer array nums and an integer k
    - Return the k most frequent elements in any order
        - must be better then O(nlogn) time
    Time: O(N), Space: O(N)
*/

/*
    Intuition:
    - record frequency with unordered_map
    - use bucket sort for O(N) time
        - Create a vector of buckets where the index represents frequency, and each bucket holds the elements with that frequency.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto n : nums) {
        m[n]++;
    }

    vector<vector<int>> bucket(nums.size() + 1);
    for (auto n : m) {
        bucket[n.second].push_back(n.first);
    }

    vector<int> ans;
    for (int i = bucket.size() - 1; i >= 0; i--) {
        for (int num : bucket[i]) {
            if (ans.size() == k) break;
            ans.push_back(num);
        }
    }

    return ans;
}