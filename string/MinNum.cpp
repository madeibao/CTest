

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string maxNum(vector<int> nums) {
    vector<string> strs;

    for(int i:nums) {
        strs.push_back(to_string(i));
    }

    auto it = [](string a, string b)-> bool { return a+b<b+a; };

    sort(strs.begin(),strs.end(),it);
    string res="";
    for(auto i:strs) {
        res+=i;
    }

    return res;
}

int main() {

    vector<int> nums {21,12};
    cout<<maxNum(nums)<<endl;
    return 0;
}

