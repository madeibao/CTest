



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int nums[26] = {0};
    string str = "abcdefghijklmnnnnn";

    for(auto i:str) {
        nums[i-'a']++;
    }

    for(auto i:nums) {
        cout<<i<<" ";
    }
    return 0;
}

