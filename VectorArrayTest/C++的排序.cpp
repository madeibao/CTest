
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 冒泡排序
void bubbleSort(int nums[], int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1-i;j++) {
			if(nums[j]>nums[j+1]) {
				swap(nums[j],nums[j+1]);
            }
        }
    }
}

// 插入排序
void insertSort(int nums[], int n) {
	for(int i=0;i<n;i++) {
		int minIndex = i;
		for(int j= i+1;j<n;j++) {
			if(nums[j]<nums[minIndex]) {
				minIndex = j;
			}
		}
		swap(nums[minIndex],nums[i]);
	}
}

// 选择排序
void selectSort(int nums[],int n) {
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(nums[i]>nums[j]) {
				swap(nums[i],nums[j]);
			}
		}
	}
}

// 快速排序
void quickSort(int array[], int start, int last) {
    int i = start;
    int j = last;
    int temp = array[i];
    if (i < j) {
        while (i < j) {
            while (i < j &&  array[j]>=temp )
                j--;
            if (i < j) {
                array[i] = array[j];
                i++;
            }

            while (i < j && temp > array[i])
                i++;
            if (i < j) {
                array[j] = array[i];
                j--;
            }
        }
        //把基准数放到i位置
        array[i] = temp;
        //递归方法
        quickSort(array, start, i - 1);
        quickSort(array, i + 1, last);
    }
}

//归并排序
void merge(vector<int>& v, int left, int mid, int right){
	vector<int> temp = v;
	int i = left, j = mid + 1;
	int index = left;
	while(i <= mid || j <= right){
		if(i > mid){
			v[index++] = temp[j];
			j++;
		}
		else if(j > right){
			v[index++] = temp[i];
			i++;
		}
		else if(temp[i] < temp[j]){
			v[index++] = temp[i];
			i++;
		}
		else{
			v[index++] = temp[j];
			j++;
		}
	}
}

void merge_Sort(vector<int>& v, int left, int right){
	if(left >= right) return;
	int mid = (left + right) / 2;
	merge_Sort(v, left, mid);
	merge_Sort(v, mid + 1, right);
	if(v[mid] > v[mid + 1]){
		merge(v, left, mid, right);
	}
}

void mergeSort(vector<int>& v){
	int n = v.size();
	merge_Sort(v, 0, n - 1);
}


int main(int argc, char *argv[]) {

	int nums[] = {2,3,11,3,3,4,5,6,4,9,10,29,10};
	vector<int> res = {2,2,10,3,9,12,3,9,13,19};

	selectSort(nums,sizeof(nums)/sizeof(nums[0]));
    cout<<endl;
	quickSort(nums,0,sizeof(nums)/sizeof(nums[0])-1);
	for(auto t:nums) {
		cout<<t<<endl;
	}

	mergeSort(res);
	for(int i=0;i<res.size();i++) {
		cout<<res.at(i)<<" ";
	}
	return 0;
}
