

#include "iostream"
#include "bits/stdc++.h"


using namespace std;

bool getLen(int* nums) {

	// 数组的长度值
	int len;

	len = sizeof(nums)/sizeof(int);

	int len2;

	len2 = sizeof(nums)/sizeof(*nums);

	return len2 ==len;  // 1
}

int main(int argc, char** argv) {

	int arr[] = {1,2,3,4};
	cout<<getLen(arr);  // 1
	return 0;
}


