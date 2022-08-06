

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int len = nums.size();
    int result=0;
       for(int i=0;i<len;i++){
           result ^=nums[i];
       }
        return result;
 }
};
int main(){
    vector<int> ves  ={1,1,2};
    Solution s;
    int num= s.singleNumber(ves);
    cout<<num;
    return 0;
}


