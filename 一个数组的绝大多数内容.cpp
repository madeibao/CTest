

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target)
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(target==nums[i])
            {
                count++;
                if(count>n/2)
                {
                    return true;
                }
            }
            else if(nums[i]>target)
            {
                return false;
            }
        }
        return false;
    }
};
int main() {
    vector<int> res = {2,4,5,5,5,5,5,6,6};
    int target =5;
    Solution s;
    cout<<s.isMajorityElement(res,target)<<endl;
    return 0;
}



