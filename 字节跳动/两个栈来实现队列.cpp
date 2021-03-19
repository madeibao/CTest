
// 用两个栈来实现队列。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int val=stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char** argv ) {


	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.pop()<<endl;
	return 0;
}