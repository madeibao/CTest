

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void Sort(vector<int>& nums){

        bool flag = false;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size()-1-i;j++) {

                if(nums[j]>nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    flag = true;
                }

            }
            if(!flag) {
                break;
            }
        }

    }

};



int main(int argc, char* argv[]) {

	vector<int> nums = {1,2,1,2,2,3};
    Solution s2;
    S2.Sort(nums)<<endl;
    return 0;

}