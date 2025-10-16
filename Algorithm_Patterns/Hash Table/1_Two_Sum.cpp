#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given an array of integers nums and an integer target
    - Return indices of the two numbers such that they add up to target.
    Time: O(1) [Hash map find and insert are O(1) average case due to internal hashing], Space: O(n)
*/

/*
    Note:
    - using a unordered map (aka hash-map), allows O(1) look-ups making it faster than O(N^2) brute-force method
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if (m.find(n) != m.end()) {
            return {i, m[n]};
        }

        int reminder = target - n;
        m[reminder] = i;
    }

    return {};
}