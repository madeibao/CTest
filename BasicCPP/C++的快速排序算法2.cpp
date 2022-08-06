



#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void quickSort(vector<int>&, int,int);

int main() {
	int a[]  = {7,3,2,1,4,5,6};
	vector<int> res(a, a+7);
	quickSort(res,0,6);
	cout<<"--------------------------------"<<endl;
	for(int i=0;i<res.size();i++) {
		cout<<res[i]<<endl;
	}

	system("pause");

	return 0;
}


void quickSort(vector<int>& a, int low, int high) {


	if(low>=high) {
		return;
	}

	int standard = a[low];
	int left = low;
	int right = high;


	while(left<right) {
		while(left<right) {

			if(standard<=a[right]) {
				right -=1;
			}
			else {
				a[left] = a[right];
				left +=1;
				break;
			}
		}

		while(left<right) {
			if(standard>=a[left]) {
				left +=1;
			}
			else {
				a[right] =a[left];
				right -=1;
				break;
			}
		}

		a[left] = standard;
		quickSort(a,low, left-1);
		quickSort(a,right+1,high);
	}
}
