

#include<iostream>
#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int find(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {

    vector<int> res  = {2,4,5,6,9};
    int target =  6;
    Solution s; 
    cout<<s.find(res, target)<<endl;
    
    return 0;
}