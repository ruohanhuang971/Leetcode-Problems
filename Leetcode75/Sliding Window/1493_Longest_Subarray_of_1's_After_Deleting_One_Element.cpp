#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int longestSubarray(vector<int>& nums) {
        int start = 0;
        int zeros = 0;
        int size = 0;

        for (int i = 0; i < nums.size(); i++) {
            // if encountering an zero
            if (nums[i] == 0) {
                zeros++;
            }
            // if that zero is over the limit -> while loop until condition is satified 
            while (zeros > 1) {
                if (nums[start] == 0) {
                    zeros--;
                }
                start++;
            }
            // get the max size (no including the zero so no +1)
            size = max(size, i - start);
        }

        // if there are no zero -> still remove an element (as per condition)
        return (size == nums.size()) ? size - 1 : size;
    }