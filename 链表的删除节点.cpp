#include "iostream"
#include <bits/stdc++.h>

using namespace std;

struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int v) {
		if(head==nullptr) {
			return nullptr;
		}

		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode* pre= dummy;
		ListNode* cur = head;

		while(cur->val!=v) {
			pre = cur;
			cur = cur->next;
		}

		pre->next = cur->next;
		return dummy->next;
	}
};

int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* h2   = new ListNode(2);
	ListNode* h3   = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	int val = 3;
	ListNode* res;
	Solution s;
	res = s.deleteNode(head, val);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}
