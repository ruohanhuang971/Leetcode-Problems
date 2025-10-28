#include <iostream>
#include <vector>
using namespace std;

/*
    Find the index of the first true element in a Sorted Boolean Array. If there is no true element, return -1.

    Time: O(logN), Space: O(1)
*/

int find_boundary(std::vector<bool>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int bound_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == true) {
            right = mid - 1;
            bound_index = mid;
        } else {
            left = mid + 1;
        }
    }

    return bound_index;
}