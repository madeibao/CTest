


#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 5;

    bool found = std::binary_search(nums.begin(), nums.end(), target);

    if (found) {
        std::cout << "Element found" << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}