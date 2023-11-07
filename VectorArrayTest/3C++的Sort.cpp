

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> nums = {22,3,1,2,3,4,3};

    sort(nums.begin(),nums.end());  // 正序排序
    for(auto i:nums) {
        cout<<i<<" ";
    }

    return 0;
}



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> nums = {22,3,1,2,3,4,3};
    sort(nums.rbegin(),nums.rend());  // 逆序排序
    for(auto i:nums) {
        cout<<i<<" ";
    }

    return 0;
}
