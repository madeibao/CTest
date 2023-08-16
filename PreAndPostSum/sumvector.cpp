

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i = 1; i < nums.size(); i ++)
            res[i] = res[i - 1] + nums[i];
        return res;
    }
};

int main() {


    vector<int> random = {1, 2, 3, 4, 5};
    Solution s2;
    vector<int> res;
    res = s2.runningSum(random);
    for(int i:res) {
        cout<<i<<" ";
    }
}
