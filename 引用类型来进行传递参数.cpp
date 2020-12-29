
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        for(unsigned int i = 0; i < nums.size();i++) {
            nums[i]+=1;
        }
        return nums;
    }
};

int main() {
    vector<int>res = {1,2,3,4,5,6,7,8,9};
    vector<int> temp;
    solution s;
    temp= s.maxSubArray(res);
    for(unsigned int i=0;i<temp.size();i++) {
        cout<<temp[i]<<endl;
    }
    cout<<"-------------------------------"<<endl;
    for(unsigned int i=0;i<res.size();i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}
