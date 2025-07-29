#include <iostream>
#include <vector>
using namespace std;

/*
    Intuition:
    Start with the widest container and moves the pointers inward based on the comparison of heights.
    Decreasing the width of the container can only lead to a larger area if the height of the new boundary is greater. 

    Time Complexity: O(N), Space Complexity: O(1)
*/

int maxArea(vector<int>& height) {
        int maxVolume = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int curArea = (right - left) * min(height[right], height[left]);
            maxVolume = max(curArea, maxVolume);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxVolume;
    }