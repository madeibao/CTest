
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void push(int node) {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int num = stack1.top();
            stack1.pop();
            return num ;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};




int main(int argc, char** argv) {


	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
	return 0;
}
