#include <iostream>
#include <vector>
using namespace std;

/*
    greedy approach: (still very hard to wrap my mind around this)
    We want to find three increasing numbers in order. Instead of checking all possible triplets, 
    greedily track the smallest and second smallest numbers seen so far. If we find a third number 
    that is bigger than both, we have found a valid triplet.
*/ 

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();

    int smallest = INT_MAX;
    int middle = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (nums[i] <= smallest) {
            smallest = nums[i];
        } else if (nums[i] <= middle) {
            middle = nums[i];
        } else {
            return true;
        }
    }
    return false;
}