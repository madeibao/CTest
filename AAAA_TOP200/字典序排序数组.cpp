


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {

    	auto it = [](const string stra, const string strb) {
    		return stra<strb;
    	};

    	vector<string> strs;
    	for(int i=0;i<n;i++) {
    		strs.push_back(to_string(i+1));
    	}

    	sort(strs.begin(), strs.end(),it);

    	vector<int> res(n);
    	for(int i=0;i<strs.size();i++) {
    		res[i] = stoi(strs[i]);
    	}

    	return res;
    }
};

int main(int argc, char** argv){

	Solution s;
	vector<int> res;
	int n= 13;
	res = s.lexicalOrder(n);
	for(auto i:res) {
		cout<<i<<" ";
	}
	return 0;
}
