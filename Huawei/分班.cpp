


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char** argv) {
	string input {};
	vector<int> classStr[2] = {};

	long long currNum {0};
	int classTag = 1;
	unordered_map<int,int> check {};
	while (cin>>input) {

		char tag = input[input.size() - 1];
		currNum = atoll(&input[0]);

		if(currNum<=0||currNum>999) {
			cout<<"ERROR";
			return 0;
		}

		if(tag=='N') {
			classTag = 1- classTag;
		}

		if(check[currNum]!=0) {
			cout<<"ERROR";
			return 0;
		}

		check[currNum] = 1;
		classStu[classTag].push_back(currNum);
	}


	if(classStu[0].size()+classStu[1].size()>999) {
		cout<<"ERROR";
		return 0;
	}


	for(int i=0;i<2;i++){
		sort(classStu[i].begin(),classStu[i].end());
	}

	if(!classStu[0].empty()&&!classStu[1].empty()&&classStu[0].front()>classStu[1].front()) {
		swap(classStu[0],classStu[1]);
	}

	for(int i=0;i<2;i++) {
		for(auto const stu:classStu[i]) {
			cout<<stu<<" ";
		}
		if(!classStu[i].empty()) {
			cout<<"\n";
		}
	}

	return 0;
}
