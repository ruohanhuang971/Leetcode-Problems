/* 
    Prompt: You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, 
    and '1' if it contains one ball.

    In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. 
    Note that after doing so, there may be more than one ball in some boxes.

    Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
    Each answer[i] is calculated considering the initial state of the boxes.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

// simple method
// vector<int> minOperations(string boxes) {
//     vector<int> ans;
//     for (int i = 0; i < boxes.size(); i++) { // for each slot
//         int sumMoves = 0;
//         for (int slot = 0; slot < boxes.size(); slot++) {
//             // calculate how far the slot checked is from i-th slot
//             if (boxes[slot] == '1') {
//                 sumMoves += abs(i - slot);
//             }
//         }
//         ans.push_back(sumMoves);
//     }

//     return ans;
// }

// one pass method
vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n, 0); // declear vector with n elements, all 0s
    
    int ballsToLeft = 0; int movesToLeft = 0;
    int ballsToRight = 0; int movesToRight = 0;
    
    for (int i = 0; i < boxes.size(); i++) { // for each slot left & right pass
        ans[i] += movesToLeft;
        ballsToLeft += boxes[i] - '0'; // add to num balls to left, convert '1' -> 1
        movesToLeft += ballsToLeft; // calculate new number of moves

        ans[n - 1 - i] += movesToRight;
        ballsToRight += boxes[n - 1 - i] - '0';
        movesToRight += ballsToRight;
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
    string boxes = "001011";
    vector<int> ans = minOperations(boxes);
    printArray(ans);
}