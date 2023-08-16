


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);

	vector<int>::iterator it = find(nums.begin(), nums.end(),6);

	if(it!=nums.end()) {
		cout<<*it<<endl;
	}
	else {
		cout<<"can not find the value"<<endl;
	}
	return 0;
}





