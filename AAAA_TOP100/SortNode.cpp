
// 给一个链表来排序

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
    ListNode* sortList(ListNode* head) {

    	if(head==nullptr) {
    		return nullptr;
    	}
    	if(head->next == nullptr) {
    		return head;
    	}
    	// 将链表来中间进行断掉
   		ListNode* p1 = head;
   		ListNode* p2 = head;

   		while (p2->next!=nullptr&&p2->next->next!=nullptr) {
   			p1 = p1->next;
   			p2 = p2->next->next;
   		}

      // 将链表从中间断开
   		ListNode* temp = p1;
   		p1 = p1->next;
   		temp->next = nullptr;

   		ListNode* L = sortList(head);
   		ListNode* R = sortList(p1);

   		return mergeTwoLists(L,R);
    }


    // 辅助函数，两个链表的归并排序
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    	ListNode* dummy = new ListNode(-1);
    	ListNode* res = dummy;

    	while (l1&&l2) {
    		if(l1->val<l2->val) {
    			res->next = l1;
    			l1 = l1->next;
    		}
    		else {
    			res->next = l2;
    			l2 = l2->next;
    		}
    		res = res->next;
    	}

    	if(l1) {
    		res->next = l1;
    	}

    	if(l2) {
    		res->next = l2;
    	}

    	return dummy->next;
    }
};

int main() {
	ListNode* a = new ListNode(9);
	ListNode* b = new ListNode(8);
	ListNode* c = new ListNode(7);
	ListNode* d = new ListNode(6);
	ListNode* e = new ListNode(10);
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
	res = s.sortList(a);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;

}



