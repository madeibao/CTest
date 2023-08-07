


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

// class CQueue {
//     stack<int> stack1,stack2;
// public:
//     CQueue() {
//         while (!stack1.empty()) {
//             stack1.pop();
//         }
//         while (!stack2.empty()) {
//             stack2.pop();
//         }
//     }
    
//     void appendTail(int value) {
//         stack1.push(value);
//     }
    
//     int deleteHead() {
//         if (stack2.empty()) {
//             while (!stack1.empty()) {
//                 stack2.push(stack1.top());
//                 stack1.pop();
//             }
//         } 
//         if (stack2.empty()) {
//             return -1;
//         } else {
//             int deleteItem = stack2.top();
//             stack2.pop();
//             return deleteItem;
//         }
//     }
// };



class CQueue {
private:
	stack<int> stack1, stack2;

public:
	CQueue() {
		while(!stack1.empty()) {
			stack1.pop();
		}

		while (!stack2.empty()) {
			stack2.pop();
		}
	}

	// 
	// 两个栈来实现一个队列
	// 栈一 首先进入元素内容。


	void appendTail(int val) {
		stack1.append(val);
	}


	// 删除队首的元素内容。
	int deleteHead() {
		// 辅助栈2

		if(stack2.empty()) {

			// 把栈2的元素内容持续的弹出来。
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}


		// 如果此时栈2 是空的栈
		if(stack2.empty()) {
			return -1;
		}
		else {
			int topNum = stack2.top();
			stack1.pop();
			return topNum;
		}
	}
};