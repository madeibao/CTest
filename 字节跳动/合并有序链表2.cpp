
#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

struct ListNode {	
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr){}

};


// 链表首先是递归。
class Solution {
public:
	ListNode* combine(ListNode* heada ,ListNode* headb) {

		if(heada==nullptr) {
			return headb;
		}

		if(headb==nullptr) {
			return heada;
		}

		ListNode* res=nullptr;

		if(heada->val<=headb->val) {
			res = heada;
			res->next = combine(heada->next,headb);
		}
		else {
			res = headb;
			res->next = combine(heada, headb->next);
		}

		return res;
	}
};


int main(int argc, char* argv[]) {


	ListNode* head = new ListNode(1); 
	ListNode* h2 = new ListNode(2);

	head->next = h2;
	h2->next = nullptr;


	ListNode* m = new ListNode(2);
	ListNode* m2 = new ListNode(3);
	m->next = m2;
	m2->next = nullptr;

	Solution s;
	ListNode * res;
	res =s.combine(head, m);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}