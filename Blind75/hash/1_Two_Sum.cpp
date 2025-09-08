#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    Time: O(1) [Hash map find and insert are O(1) average case due to inernal hashing], Space: O(n)
    using a unordered map (aka hash-map), allows O(1) look-ups making it faster than O(N^2) brute-force method
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (m.find(complement) != m.end()) {
            return {m[complement], i};
        }
        m[nums[i]] = i;
    }
    return vector<int>();
}