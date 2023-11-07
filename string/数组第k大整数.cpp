

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(),[&](auto a, auto b){
            if(a.size() == b.size())
                return a > b;
            return a.size() > b.size();
        });
        return nums[k-1];
    }
};


int main() {

    vector<string> nums = {"3","6","7","10"};
    int k =4;
    Solution s2;
    cout<<s2.kthLargestNumber(nums,k)<<endl;
    return 0;
}
