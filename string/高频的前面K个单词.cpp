
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        //  存到哈希结构里
        for(auto num : nums)   {
            m[num] +=1;
        }

        vector<pair<int,int>>v;
        vector<int>ans;
        for(auto it : m)        //  存到用于对value排序的容器里
            v.push_back(make_pair(it.first,it.second));
    
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{return a.second>b.second;}  );
        //  对容器中的pair按照出现次数从大到小排序
        /*
            C++ 的lambda表达式和java的略有区别
        */
        for(int i=0;k;++i,--k)
            ans.push_back(v[i].first);

        return ans;
    }
};


int main(int argc, char* argv[]) {


    vector<int> nums = {1,1,1,2,2,3};
    int  k = 2;
    vector<int> res;
    Solution s;
    res = s.topKFrequent(nums, k);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}