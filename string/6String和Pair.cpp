

leetcode 2418 
2418. 按身高排序


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<string, int>> nums;

        for(int i=0,j=0;i<names.size()&&j<heights.size();i++,j++) {
            nums.push_back(make_pair(names[i],heights[j]));
        }

        for(auto i:nums){
            cout<<i.first<<" "<<i.second<<endl;
        }

        sort(nums.begin(),nums.end(),cmp);
        vector<string> res;

        for(auto i:nums) {
            res.push_back(i.first);
        }
        return res;
    }

    static bool cmp(const pair<string, int> a, const pair<string, int> b) {
        return a.second > b.second;
    }

};

int main() {

    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};

    vector<string> res;

    Solution s2;

    res = s2.sortPeople(names,heights);
    for(auto i:res) {
        cout<<i<<endl;
    }
    return 0;
}
