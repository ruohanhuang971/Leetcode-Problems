#include <iostream>
#include <vector>

/*
    similar to the knapSack problem
    int knapSack(int W, int wt[], int val[], int n) {

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(knapSack(W, wt, val, n - 1),
         val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
}

*/

void threeSumHelper(std::vector<int> nums, std::vector<std::vector<int>> &ans, std::vector<int> cur) {
    // if size is 3, add to list
    int curSize = cur.size();
    if (cur.size() == 3 && (cur[0] + cur[1] + cur[2] == 0)) {
        // sort
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < 3; j++) {
                if (cur[i] > cur[j]) {
                    int temp = cur[i];
                    cur[i] = cur[j];
                    cur[j] = temp;
                }
            }
        }
        // if same don't add
        bool toAdd = true;
        for (int i = 0; i < ans.size(); i++) {
            if (cur[0] == ans[i][0] && cur[1] == ans[i][1] && cur[2] == ans[i][2]) {
                toAdd = false;
            }
        }
        if (toAdd) {
            ans.push_back(cur);
        }     
        return;
    }

    if (nums.size() == 0) {
        return;
    }

    int newInt = nums[0];
    std::vector<int> tail(nums.begin() + 1, nums.end());

    // only add if it is different from previous entries
    // add or not add to list
    if (curSize == 0) {
        threeSumHelper(tail, ans, cur);
        cur.push_back(newInt);
        threeSumHelper(tail, ans, cur);
    } else if (curSize == 1) {
        threeSumHelper(tail, ans, cur);
        cur.push_back(newInt);
        threeSumHelper(tail, ans, cur);
    } else if (curSize == 2) {
        threeSumHelper(tail, ans, cur);
        cur.push_back(newInt);
        threeSumHelper(tail, ans, cur);
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> cur;
    threeSumHelper(nums, ans, cur);
    return ans;
}

int main() {
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto k = threeSum(v);

    std::cout << "answers: " << std::endl;
    for (int i = 0; i < k.size(); i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << k[i][j] << " ";
        }
        std::cout << std::endl;
    }
}