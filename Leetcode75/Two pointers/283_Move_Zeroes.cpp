#include <iostream>
#include <vector>
using namespace std;

/*
    The intuation is pretty easy but for some reason I got hard stuck on this one
    Time complexity: O(n), Space complexity: O(1)
*/

void moveZeroes(vector<int>& nums) {
    int posNum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[posNum];
            nums[posNum] = temp;
            posNum++;
        }
    }
}