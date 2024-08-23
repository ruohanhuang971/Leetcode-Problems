#include <iostream>
#include <vector>

/*
    Similar to binary search:
    int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
  return -1;
}
*/

int searchInsert(std::vector<int>& nums, int target) {
    int low = 0;
    int hi = nums.size() - 1; // Initialize hi to nums.size() - 1
    int mid;

    while (low <= hi) {
        mid = low + (hi - low) / 2;

        // Check if target is present at mid
        if (nums[mid] == target) {
            return mid;
        }

        // If target greater, ignore left half
        if (nums[mid] < target) {
            low = mid + 1;
        } else { // If target is smaller, ignore right half
            hi = mid - 1;
        }
    }

    // If not found, `low` is the insert position
    return low;
}

int main() {
    std::vector<int> v = {1, 3, 5, 6};
    int target = 7;
    auto k = searchInsert(v, target);

    std::cout << "answers: " << k << std::endl;
}