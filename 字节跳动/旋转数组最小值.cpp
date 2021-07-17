
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else if(nums[mid]<nums[r])
                r=mid;
            else
                r--;
        }
        return nums[l];
    }
};

int main(int argc, char** argv) {

    vector<int> res {1,3,5};
    Solution s;
    cout<<s.findMin(res)<<endl;
    return 0;

}
