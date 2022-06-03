


#include "iostream"
#include "bits/stdc++.h"

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
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		if(head == nullptr||head->next == nullptr) {
			return head;
		}

		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode* p = dummy;
		ListNode* q = head;

		// 指针移动
		for(int i=0;i<m-1;i++) {
			p = p->next;
			q = q->next;
		}

		for(int i=0;i<n-m;i++) {
			ListNode* temp = q->next;
			q->next = temp ->next;
			temp ->next = p->next;
			p ->next = temp;
		}
		return dummy->next;
	}
};


int main() {

	ListNode* a = new ListNode(9);
	ListNode* b = new ListNode(8);
	ListNode* c = new ListNode(7);
	ListNode* d = new ListNode(6);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(4);
	ListNode* g = new ListNode(3);
	ListNode* h = new ListNode(2);
	ListNode* j = new ListNode(1);


	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = j;
	j->next = nullptr;


	Solution s;
	ListNode * res;
	res = s.reverseBetween(a, 3, 5);
	while (res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}
