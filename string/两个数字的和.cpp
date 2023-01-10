

#include<iostream>
#include<vector>

using namespace std;
class Solution {

public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if(numbers.size()<2) {
            return {};
        }

        int left =0,right = numbers.size()-1;
        while(left<right) {
            int temp = numbers[left] + numbers[right];
            if(temp<target) {
                left++;
            }
            else {
                if(temp>target) {
                    right--;
                }
                else {
                    return {left+1,right+1};
                }
            }
        }
        return {};
    }
};


int main() {

    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> res;
    Solution s;
    res = s.twoSum(vec, target);
    for(unsigned int i=0;i<res.size();i++) {
        cout<<res[i]<<" "<<endl;
    }
    return 0;
}


