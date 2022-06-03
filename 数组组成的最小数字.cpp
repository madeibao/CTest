

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    static bool cmp(const string a, const string b) {

        string stra = a+b;
        string strb = b+a;
        return stra<strb;
    }
    string minNum(vector<int>& nums) {

        string res ="";
        if(nums.size()<=0) {
            return res;
        }

        vector<string> strs;
        for(auto i:nums) {
            strs.push_back(to_string(i));
        }

        sort(strs.begin(),strs.end(),cmp);
        for(auto j:strs) {
            res+=j;
        }
        return res;
    }
};


int main() {

    vector<int> res = {10,2};
    Solution s;
    cout<<s.minNum(res)<<endl;
    return 0;
}
