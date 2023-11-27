


//-----------------------------------------------------------------------------
// 统计一个vector中的指定元素的数量。


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

    vector<int> nums = {1,2,2,3,4,5,2,2,2,};

    int a = count(nums.begin(), nums.end(), 2);

    cout<<a<<endl;

    return 0;
}