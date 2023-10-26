
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	unordered_map<int, int> map2;//hash计数

    vector<int> nums = {1,1,2,2,2,3,3,4,4,5,5,5,5,6,6,};

	for (int i = 0; i < nums.size(); i++) {
		map2[nums[i]]++;
	}


	//-----------------------------------------------------------------------
	// 更加简单的写法
	
	unordered_map<int, int> map3;//hash计数

	for(auto i:n) {
		map3[i]++;
	}

	for ( auto it = map2.begin(); it != map2.end(); ++it ) {
		cout << " " << it->first << ":" << it->second<<endl;
	}

	cout<<endl;
	for ( auto it = map3.begin(); it != map3.end(); ++it ) {
		cout << " " << it->first << ":" << it->second<<endl;
	}


	return 0;
}
