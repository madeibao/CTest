


#include<iostream>
#include<vector>
using namespace std;

int binarySearchRecursive(vector<int> vec, int target, int left, int right) {

    if (left > right) {
        return -1;
    }

    int mid  = left + (right-left)/2;

    if (vec[mid] == target) {
        return mid;
    }
    else if (vec[mid] > target) {
        return binarySearchRecursive(vec, target, left, mid-1);
    }
    else {
        return binarySearchRecursive(vec, target, mid+1, right);
    }

}

int binarySearch(vector<int> vec, int target) {
    return binarySearchRecursive(vec, target, 0, vec.size()-1);
}



int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 5;

    int index = binarySearch(nums, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
