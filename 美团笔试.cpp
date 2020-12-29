
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int getNum(int nums[], int n ) {

    unordered_map<int, int> map2;

    int maxNum = 0;

    for(int i=0;i<n;i++) {
        map2[nums[i]]+=1;
    }

    for(auto it=map2.begin();it!=map2.end();it++) {
        if(it->second>maxNum) {
            maxNum=it->second;
        }
    }
    return maxNum;

}

int main(int argc, char* argv[]) {

    int n,x ;
    int nums[1000];
    cin>>n>>x;

    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    for(int i=0;i<n;i++) {
        nums[i] = nums[i]|x;
    }

    cout<<getNum(nums,n);
    return 0;

}
