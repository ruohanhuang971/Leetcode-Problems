#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

    int longestOnes(vector<int>& nums, int k) {
        int size = 0;
        int start = 0;
        int flipsLeft = k;
        for (int i = 0; i < nums.size(); i++) {
            // if encountering an zero
            if (nums[i] == 0) {
                flipsLeft--;
            }
            // if there are no flips left, slide window to right
            if (flipsLeft < 0) {
                if (nums[start] == 0) {
                    flipsLeft++;
                }
                start++;
            }

            // size of window is (right bound - left bound) + 1
            size = max(size, i - start + 1);
        }

        return size;
    }