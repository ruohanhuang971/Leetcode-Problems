#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
        std::vector<int> included;
        for (int i = 0; i < nums.size(); i++) {
            bool repeat = false;
            for (int j = 0; j < included.size(); j++) {
                if (nums[i] == included[j]) {
                    repeat = true;
                    break;
                }
            }
            if (repeat) {
                continue;
            }
            included.push_back(nums[i]);
        }
        nums = included;
        return included.size();
    }
    
int main() {
    std::vector<int> v = {1,1,2};
    int k = removeDuplicates(v);

    for (int i = 0; i < k; i++) {
        std::cout << v[i] << " ";
    }
}

