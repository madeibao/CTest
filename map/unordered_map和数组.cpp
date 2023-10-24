
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	unordered_map<int, int> map2;//hash计数

    vector<int> nums = {1,1,2,2,2,3,3,4,4,5,5,5,5,6,6,};

	for (int i = 0; i < nums.size(); i++) {
		map2[nums[i]]++;
	}

	for ( auto it = map2.begin(); it != map2.end(); ++it ) {
		cout << " " << it->first << ":" << it->second<<endl;
	}


	return 0;
}
