// 使用泛型来实现C++的编程。

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<class T>
void selectSort(T nums[], int n) {

	for(int i=0;i<n;i++) {
		int minIndex = i;
		for(int j=i+1;j<n;j++) {
			if(nums[j] < nums[minIndex]){
				minIndex = j;
			}
		}
		swap(nums[minIndex], nums[i]);
	}
}


int main(int argc, char* argv[]) {

	int nums[] ={2,2,3,1,2,3,3,4,4,20,};

	double nums2[] = {2.0,3.0,2.0,4.0};
	selectSort(nums, sizeof(nums2)/sizeof(nums2[0]));
	selectSort(nums, sizeof(nums)/sizeof(nums[0]));
    for(auto j:nums) {
        cout<<j<<endl;
    }
    cout<<endl;

    for(auto m:nums2) {
    	cout<<m<< " ";
    }
}



/**
def Selectionsort1(A):
    for i in range(len(A)):
        min = i
        for j in range(i + 1, len(A)):  # 上一个值右边的数组
            if A[min] > A[j]: 		    # 使min为最小值，遇到比min小的值就赋值于min
                min = j
        A[i], A[min] = A[min], A[i]     # 交换最小值到左边
    return A

list2 = [2, 1, 2, 3, 3, 4, 5, 6, 67]
print(Selectionsort1(list2))

*/