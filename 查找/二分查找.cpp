

// 二分查找的多种的写法实现

#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target element not found
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 5;

    int index = binarySearch(nums, target);

    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
