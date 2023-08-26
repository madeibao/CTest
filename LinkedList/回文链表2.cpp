


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef struct ListNode {

	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr){};
}ListNode;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
	    ListNode* p;

        p = head;
    	stack<int> stack;
    	while(p) {
    		stack.push(p->val);
    		p = p->next;
    	}

    	p = head;
    	while(p!=nullptr) {
    		if(p->val!=stack.top()) {
    			return 0;
    		}
            stack.pop();
    		p = p->next;
    	}

    	return 1;
    }
};



int main(int argc, char** argv) {


	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(1);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	Solution s;
	cout<<s.isPalindrome(head)<<endl;
	return 0;
}







