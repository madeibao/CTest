

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        if(nums.size()==0) return 0;
        if(nums[0]=='0') return 0;
        vector<int>dp(nums.size()+1);
        dp[0] = 1;
        for(int i=1;i<nums.size();++i){
            dp[i] = dp[i-1];
            if(nums[i]=='0'){
                if(nums[i-1]=='0') return 0;
            }else{
                if((nums[i-1]=='1')||(nums[i-1]=='2'&&nums[i]<='6')){
                    dp[i] += i > 1?dp[i-2] :1;  // 区别前两位
                }
            }
        }
        return dp[nums.size()-1];
    }
};


int main(int argc, char** argv ) {

    string str = "12";
    Solution s;
    cout<<s.solve(str)<<endl;
    return 0;
}



