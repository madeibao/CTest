

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr) {}
	ListNode(int v,ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    	// 递归必须有结束的条件。
    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}

    	ListNode *temp = head->next;
    	ListNode *newhead = swapPairs(temp->next);
    	head->next = newhead;
    	temp->next = head;
    	return temp;
    }
};

int main(int argc, char** argv) {

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(4);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(2);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

	Solution s;
	ListNode *res;

	res=s.swapPairs(head);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}
