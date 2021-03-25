
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr)	{}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		// 如果与后面的内容相等，则不断的像后面删除。
		if(head->next!=nullptr&&head->val==head->next->val) {
			while(head->next!=nullptr&&head->val==head->next->val) {
				head = head->next;
			}
			return deleteDuplicates(head->next);
		}
		else {
			head->next = deleteDuplicates(head->next);
		}
		return head;
	}
};

int main() {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;
	Solution s;
	ListNode* res;
	res = s.deleteDuplicates(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}

