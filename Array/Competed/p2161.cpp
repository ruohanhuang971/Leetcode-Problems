/*
    You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums
    such that the following conditions are satisfied:

    1. Every element less than pivot appears before every element greater than pivot.
    2. Every element equal to pivot appears in between the elements less than and greater than pivot.
    3. The relative order of the elements less than pivot and the elements greater than pivot is maintained.
        More formally, consider every pi, pj where pi is the new position of the ith element and
        pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
*/

#include <iostream>
#include <vector>
using namespace std;

// not space good -> create 3 new arrays 
// O(n)
// vector<int> pivotArray(vector<int>& nums, int pivot) {
//     vector<int> lesserToPivot;
//     vector<int> equalToPivot;
//     vector<int> greaterToPivot;

//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] < pivot) {
//             lesserToPivot.push_back(nums[i]);
//         } else if (nums[i] > pivot) {
//             greaterToPivot.push_back(nums[i]);
//         } else {
//             equalToPivot.push_back(nums[i]);
//         }
//     }

//     vector<int> ans;
//     for (int i = 0; i < lesserToPivot.size(); i++) {
//         ans.push_back(lesserToPivot[i]);
//     }
//     for (int i = 0; i < equalToPivot.size(); i++) {
//         ans.push_back(equalToPivot[i]);
//     }
//     for (int i = 0; i < greaterToPivot.size(); i++) {
//         ans.push_back(greaterToPivot[i]);
//     }

//     return ans;
// }

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans;
    int lessPos = 0;
    int greatPos = 0;
    int equalPos = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < pivot) {
            ans.insert(ans.begin() + lessPos, nums[i]);
            lessPos++;
            greatPos++;
            equalPos++;
        } else if (nums[i] > pivot) {
            ans.insert(ans.begin() + greatPos, nums[i]);
            greatPos++;
        } else {
            ans.insert(ans.begin() + equalPos, nums[i]);
            equalPos++;
            greatPos++;
        }
    }

    return ans;
}

void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = {-3,4,3,2};
    int pivot = 2;

    vector<int> ans = pivotArray(nums, pivot);
    printArray(ans);
}