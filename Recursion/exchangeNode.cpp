
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val):val(val){}
	ListNode(int val, ListNode* next):val(val),next(nullptr) {};

};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    	// 递归总有一个出口函数
    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}
    	
    	ListNode* node2 = head->next;

    	ListNode* res = swapPairs(node2->next);
    	head->next = res;
    	node2->next = head;
    	return node2;

    }
};

int main() {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h5 = new ListNode(5);
	ListNode* h6 = new ListNode(6);
	ListNode* h7 = new ListNode(7);
	ListNode* h8 = new ListNode(8);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = h7;
	h7->next = h8;
	h8->next = nullptr;

	ListNode* res;
	Solution s2;
	res = s2.swapPairs(head);
	while (res!=nullptr) {
		cout << res->val<<" ";
		res = res->next;
	}

}
