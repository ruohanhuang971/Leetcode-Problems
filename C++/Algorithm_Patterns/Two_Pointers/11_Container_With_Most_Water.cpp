#include <iostream>
#include <vector>
using namespace std;

/*
    - Given array height of length n. Two lines together with the x-axis form a container
    - Return the maximum amount of water a container can store.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - area will only get bigger when moving the pointer inward if wall gets taller
    - try to move the pointer that is shorter to potentially get a larger wall -> larger area
*/

int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // cout << left << " " << right << endl;

            // calc area
            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);

            // update pointers
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }