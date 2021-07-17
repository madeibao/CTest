

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
    	if(a.size()==0) {
    		return vector<int> {};
    	}

    	vector<int> left(a.size(),1);
    	vector<int> right(a.size(),1);
    	vector<int> res(a.size(),1);


    	left[0] = 1;
    	left[a.size()-1] = 1;
    	for(int i=1;i<a.size();i++) {
    		left[i] = left[i-1]* a[i-1];
    	}

    	for(int j= a.size()-2;j>=0;j--) {
    		right[j] = right[j+1]*a[j+1];
    	}

    	for(int i=0;i<a.size();i++) {
    		res[i] = left[i]*right[i];
    	}

    	return res;

    }
};

int main(int argc, char* argv[]) {

	vector<int> temp {1,2,3,4,5};
	Solution s;
	vector<int> res;
	res = s.constructArr(temp);
	for(int i=0;i<res.size();i++) {
		cout<<res[i]<<endl;
	}
	return 0;

}
