

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode* split(ListNode* head, int x) {

		if(head==nullptr) {
			return head;
		}

		ListNode* dummya = new ListNode(-1);
		ListNode* dummyb = new ListNode(-1);

		ListNode* p = dummya;
		ListNode* q = dummyb;

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

		q->next = nullptr;
		p->next = dummyb->next;
		return dummya->next;
	}
};


int main() {
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(2);


	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = nullptr;


	int x = 3;
	ListNode* res;
	Solution s;
	res = s.split(a, x);
	while (res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;

}
