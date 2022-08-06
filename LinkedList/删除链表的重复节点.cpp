
/**
	这里的删除重复节点指的是
	所有节点不重复，保留一个节点值
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int v)	:val(v),next(nullptr) {}
	ListNode(int v, ListNode* next): val(v), next(nullptr)	 {}

};


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		head->next = deleteDuplicates(head->next);
		if(head->val==head->next->val) {
			head = head->next;
		}

		return head;
	}
};


int main(int argc, char*argv[]) {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;

	Solution s;
	ListNode * res;
	res = s.deleteDuplicates(head);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res= res->next;
	}
	return 0;
}

