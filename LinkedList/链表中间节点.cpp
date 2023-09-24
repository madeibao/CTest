


#include<iostream>
#include<bits/stdc++.h>


using namespace std;
struct ListNode {

    int val;
    ListNode *next;
    ListNode(int v):val(v) {}
    ListNode(int v,ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
	ListNode* midNode(ListNode*head) {

		ListNode* slow = head;
		ListNode* fast=  head->next;

		while (fast!=nullptr && fast->next!=nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

		slow->next = nullptr;

		return head;
	}
};

int main(int argc, char** argv) {

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

	Solution s2;
	ListNode* res;
	res =s2.midNode(head);
	while (res) {
		cout << res->val << endl;
		res	= res->next;
	}

	return 0;
}
