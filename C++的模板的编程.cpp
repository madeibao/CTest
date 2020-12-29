

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// template <typename T>
template<class T>
void select(T nums[], int n) {

	for(int i=0; i<n;i++) {
		int index = i;
		for(int j=i+1;j<n;j++) {
			if(nums[j]<nums[index]) {
				index = j;
			}
		}
		swap(nums[index], nums[i]);
	}
}


int main(int argc, char* argv[]) {
	int nums[] ={2,23,3,3,3,45,65,5,6,};
	select(nums,sizeof(nums)/sizeof(nums[0]));

	for(auto i:nums) {
		cout<<i<<endl;
	}
	return 0;
}
