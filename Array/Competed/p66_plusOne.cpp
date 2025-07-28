#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    
}

int main() {
    std::vector<int> v = {1,2,3};
    auto k = plusOne(v);

    std::cout << "answers: " << std::endl;
    for (int i = 0; i < k.size(); i++) {
        std::cout << k[i] << " ";
    }
    std::cout << std::endl;
}