
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr){}
};


class Solution {
public:
	ListNode* partition(ListNode* head, int x){

		ListNode* dummy1 = new ListNode(-1);
		ListNode* dummy2 = new ListNode(-1);

		ListNode* p = dummy1;
		ListNode* q = dummy2;

		while(head!=nullptr) {
			if(head->val<x) {
				p->next = head;
				p = p->next;
			}
			else {
				q->next = head;
				q = q->next;
			}
			head = head->next;

		}

		p->next = dummy2->next;
		q->next = nullptr;
		return dummy1->next;
	}
};


int main(int argc, char* argv[]) {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(4);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(2);
	ListNode* h5 = new ListNode(5);
	ListNode* h6 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

	ListNode* res;
	Solution s;
	int x =3;
	res = s.partition(head, x);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}

	return 0;
}
