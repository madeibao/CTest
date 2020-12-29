

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& res) {

	for(int i=0;i<res.size();i++) {
		int index = res[i];
		for(int j=i+1;j<res.size();j++) {
			if(res[j]<res[index]) {
				swap(res[j],res[index]);
			}
		}
	}
	return res;
}
int main(int argc, char *argv[]) {

	vector<int> res {2,3,3,4,3,4,3,4,9,10,23,4};
	insertSort(res);

	for(int i=0;i<res.size();i++) {

		cont<<res[i]<<" ";
	}
	return 0;


}