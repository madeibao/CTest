

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    vector<vector<int>> combine(int n, int k) {

    	result.clear();
    	path.clear();
		dfs(n, k, 1);
        return result;
    }

    void dfs(int n, int k, int startIndex){
    	if(path.size()==k) {
    		result.push_back(path);
    		return;
    	}

    	for(int i=startIndex; i<=n;i++) {
    		path.push_back(i);
    		dfs(n,k,i+1);
    		path.pop_back();
    	}
    }

};

int main(int argc, char**argv) {

	int n =4;
	int k =2;
	vector<vector<int>> res;
	Solution s2;
	res =s2.combine(n,k);
	for(auto i:res) {
		for(int j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}
