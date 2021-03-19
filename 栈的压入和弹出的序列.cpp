
// 判断是否为合法的弹入和弹出的序列。
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    	stack<int> stack2;
    	int j=0;
    	for(int i:pushed) {
    		stack2.push(i);
    		if(!stack2.empty()&&stack2.top()==popped[j]) {
    			stack2.pop();
    			j++;
    		}
    	}
    	return stack2.empty();
    }
};


int main(int argc, char* argv[]) {

	vector<int> stack1 = {1,2,3,4,5};
	vector<int> stack2 = {1,2,3,4,5};
	Solution s;
	cout<<s.validateStackSequences(stack1,stack2)<<endl;

	return 0;
}
