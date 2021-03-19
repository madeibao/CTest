

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool stackOrder(vector<int> &pushed, vector<int> &popped) {
		stack<int> stack2;
		unsigned int k = 0;
		for(auto j:pushed) {
			stack2.push(j);
			while(!stack2.empty() && stack2.top()==popped[k]) {
				k+=1;
				stack2.pop();
			}
		}
		return stack2.empty();
	}
};


int main(int argc, char* argv[]) {

	Solution s;
	vector<int> pushed = {1,2,3,4,5};
	vector<int> poped = {1,2,3,4,5};
	cout<<s.stackOrder(pushed,poped)<<endl;

	return 0;
}
