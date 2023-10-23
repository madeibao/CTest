#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void brack(vector<vector<int>> &res, vector<int> temp, int start, int end) {
        if(start==end) {
            res.emplace_back(temp);
            return;
        }

        for(int i=start; i<end; i++) {
            swap(temp[i], temp[start]);
            brack(res, temp,start+1,end);
            swap(temp[start], temp[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        brack(res, nums, 0, (int)nums.size());
        return res;
    }
}
int main(int argc, char* argv[]) {
    vector<int> res ={1,2,3};
    vector<vector<int>> nums;
    Solution s;
    nums= s.permute(res);
    for(vector<int> te:nums){
        for(int j :te ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}