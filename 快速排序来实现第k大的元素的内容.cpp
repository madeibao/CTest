
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void quickSort(vector<int> &a, int low, int high) {
		int pos;
		if(low<high) {
			pos = findPos(a, low, high);
			quickSort(a, low,pos-1);
			quickSort(a, pos+1, high);
		}
	}

	int findPos(vector<int> &a, int low, int high) {
		int val = a[low];
		while(low<high) {

			while(low<high &&a[high]>val) {
				high--;
			}

			a[low] = a[high];
			while(low<high&&a[low]<=val) {
				low++;
			}
			a[high] = a[low];
		}

		a[low] = val;
		return high;
	}

	int findKth(vector<int> a, int n, int k) {
		quickSort(a,0,n-1);
		return a[n-k];
	}
};

int main(int argc, char* argv[]) {

	vector<int> res = {1,3,5,2,2,};
	int k = 3;
	int n = res.size();

	Solution s;
	cout<<s.findKth(res,n,k)<<endl;
	return 0;
}
