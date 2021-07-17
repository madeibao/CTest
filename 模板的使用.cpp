

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
T findmax(T nums[], int len) {
    T val = nums[0];
    for(int i=1;i<len;i++) {
        if(nums[i]>val) {
            val = nums[i];
        }
    }
    return val;
}


int main() {

    int nums[] ={23,2,34,5,3,3};
    int temp = findmax<int>(nums, 6);

    cout<<temp<<endl;

    double nums2[] = {2.0,3.0,4.0,2.0,9.0};
    double temp2 = findmax<double>(nums2,5);
    cout<<temp2<<endl;
    return 0;
}




