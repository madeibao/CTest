



#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void change(vector<int>& nums);
void change(vector<int>& nums) {

    for(unsigned int i=0;i<nums.size();i++) {
        nums[i]+=2;
    }
}

int main() {

    vector<int> res  {2,3,3};
    change(res);
    for(int i:res) {
        cout<<i<<" ";
    }
    return 0;
}




