#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int maxAns = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max(maxProd * nums[i], nums[i]);
        minProd = min(minProd * nums[i], nums[i]);

        maxAns = max(maxAns, maxProd);
    }

    return maxAns;
}