

#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
    int masSubArray(vector<int> &nums) {
        if(nums.size()==0) {return NULL;}
        int res = INT_MIN;
        int f_n = -1;
        for(int i=1;i<nums.size();i++) {
            f_n = max(f_n+ nums[i], nums[i]);
            res = max(f_n, res);
        }
        return res;
    }

};
int main() {
    Solution s;
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    int res = s.maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}

