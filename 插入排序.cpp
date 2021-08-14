
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void insertSort(vector<int> &a) {
	for (unsigned int i = 1; i < a.size(); i++) {

		// 下标从0开始的值
		for (unsigned int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--) {
			// 两个内容来交换
			swap(a[j], a[j + 1]);
		}
	}
}


int main(int argc, char *argv[]) {

	vector<int> res {2,3,3,4,3,4,3,4,9,10,23,4};
	insertSort(res);

	for(unsigned int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}




