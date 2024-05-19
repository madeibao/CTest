class Solution {
public:
    int findPeakElement(vector<int>& nums) {


        int left = 0;
        int right = nums.size()-1;

        while(left<right) {

            int mid = (left+right)/2;

            if(nums[mid]>nums[mid+1]) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }

        return left;
    }
};


// 输入：nums = [1,2,3,1]
// 输出：2
// 解释：3 是峰值元素，你的函数应该返回其索引 2。