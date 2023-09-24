

//---------------------------------------------------------------------
// 判断栈的弹入和弹出顺序是否相符合


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    	stack<int> stack2;
    	int i=0,j=0;

    	for(i=0;i<pushed.size();i++) {
    		stack2.push(pushed[i]);
    		while(j<popped.size()&&!stack2.empty()&&stack2.top()==popped[j]) {
    			j++;
    			stack2.pop();
    		}
    	}

    	return stack2.empty();
    }
};


int main(int argc, char** argv) {

	vector<int> pushed = {1,2,3,4,5};
	vector<int> popped = {4,5,3,2,1};

	Solution s2;
	cout<<s2.validateStackSequences(pushed, popped);

	return 0;
}
