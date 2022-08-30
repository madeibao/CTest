
/**
* 数组来组成的最小的数字。
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minNum(vector<int> & nums) {
        if(nums.size()==0) {
            return nullptr;
        }

        vector<string> strs;
        for(unsigned int i=0;i<nums.size();i++) {
            strs.push_back(to_string(nums[i]));
        }
        auto compare  = [](const string a, const string b) {return a+b<b+a;};

        sort(strs.begin(), strs.end(),compare);
        string res;
        for(unsigned int i=0;i<strs.size();i++) {
            res+= strs[i];
        }
        return res;
    }
};


int main(int argc, char **argv) {

    vector<int> res = {10,2};
    Solution s;
    cout<<s.minNum(res)<<endl;
    return 0;
}
