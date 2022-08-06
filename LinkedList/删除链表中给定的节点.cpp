
// 1 1 2 3 4 5
// 给定节点3，然后删除之

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) : val(val){}
	ListNode(int v, ListNode* next): val(v), next(nullptr)	 {}
};

class Solution2 {
public:
	ListNode* deleteNode(ListNode *head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode *pre = dummy;
		ListNode *p = head;

		while(p!=nullptr&&p->next!=nullptr) {
			if(p->val==p->next->val) {
				pre->next = p->next;
				p = p->next;
			}
			else {
				pre= p;
				p = p->next;
			}
		}
		return dummy->next;
	}
};

// 添加虚拟头节点

class Solution {
public:
	ListNode* deleteNode2(ListNode* head, int k) {

		ListNode* dummy= new ListNode(-1);
		dummy->next = head;

		ListNode* pre = dummy;

		while(pre->next!=nullptr) {
			if(pre->next->val==k) {
				pre->next = pre->next->next;
			}
			else {
				pre = pre->next;
			}
		}
		return dummy->next;
	}
};

int main(int argc, char* argv[]) {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;

	int val(3);
	ListNode* res;

	Solution s;
	res = s.deleteNode2(head,val);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}

	return 0;
}
