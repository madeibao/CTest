


//----------------------------------------------------------------
/** 
    数组来组成的最大的元素
    这里有个特殊情况是数组中可能全部 0 来组成
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto it = [](string a, string b) {
            return a+b>b+a;
        };

        vector<string> strs;
        for(auto i:nums) {
            strs.push_back(to_string(i));
        }

        sort(strs.begin(),strs.end(),it);
        string res = "";
        for(auto j:strs) {
            res+=j;
        }

        if(res[0]=='0') {
            return "0";
        }
        return res;
    }
};


int main() {

    vector<int> nums  {10,2};
    vector<int> nums2 {0,0};
    Solution s2;
    cout<<s2.largestNumber(nums)<<endl;

    return 0;
}