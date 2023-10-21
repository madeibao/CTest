

#include<bits/stdc++.h>

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
    vector<string> nums = {"2","21","12","1"};
    int k = 3;
    Solution s2;
    cout<<s2.kthLargestNumber(nums,k)<<endl;
    return 0;
}
