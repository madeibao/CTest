
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v, ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
	ListNode * reverse(ListNode *head, int left, int right) {

		ListNode *dummy = new ListNode(-1);
		dummy->next = head;

		ListNode *pre = dummy;
		ListNode *p = head;

		for(int i=0;i<left-1;i++) {
			pre = pre->next;
			p = p->next;
		}

		for(int j=0;j<right-left;j++) {
			ListNode* node = p->next;
			p->next = node->next;
			node->next = pre->next;
			pre->next = node;
		}
		return dummy->next;
	}
};

int main(int argc, char** argv ) {


	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(4);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(6);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

	int left = 2;
	int right =4;

	ListNode *res;
	Solution s;
	res = s.reverse(head, left, right);

	while (res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}

	return 0;
}
