
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRes(vector<int>& nums) {
        int x=0, y=0, n=1, m=1;

        for(unsigned int i=0;i<nums.size();i++) {
            n = n^nums[i];
        }
        vector<int> res(2,0);

        // 位运算移动。
        while((n&m)==0) {
            m = m<<1;
        }

        for(unsigned int i=0;i<nums.size();i++) {
            if((m&nums[i])!=0) {
                x = x^nums[i];
            }
            else {
                y = y^nums[i];
            }
        }

        res[0] = x;
        res[1] = y;
        return res;
    }
};


int main() {

    Solution s;
    vector<int> res ={2,2,3,3,4,4,5,8};
    vector<int> res2;
    res2=  s.getRes(res);
    for(int i=0;i<res2.size();i++) {
        cout<<res2[i]<<endl;
    }
    return 0;
}
