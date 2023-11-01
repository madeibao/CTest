

// 分割链表的内容
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v,ListNode* next): val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        	
        ListNode * a = headA;
        ListNode * b = headB;

        while (a != b) {
        	a = a ? a->next : headB;
        	b = b ? b->next : headA;
        }

        return a;

    }
};

int main(int argc, char** argv) {


	ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


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
	j->next = n3;

	Solution s;

	ListNode* res;

	res = s.getIntersectionNode(head,a);
	while ( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}


}