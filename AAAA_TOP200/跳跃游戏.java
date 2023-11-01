


class Solution {
    public boolean canJump(int[] nums) {

        int pos = nums.length-1;

        for(int i=nums.length-1;i>=0;i--) {
            if(i+nums[i]>=pos) {
                pos = i;
            }
        }

        return pos==0;
    }
}



class Solution {


    public boolean canJump(int[] nums) {

        if(nums.length==0||nums==null) {
            return true;
        }

        int ans = 0;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(ans>=i) {
                ans = max(ans,i+nums[i]);
            }
        }

        if(ans>=n-1) {
            return true;
        }

        return false;
    }
}