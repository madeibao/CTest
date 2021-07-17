


// 删除链表中的重复的节点。
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
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head||!head->next) {
			return head;
		}
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


int main(int argc, char* argv[]) {
	ListNode* head = new ListNode(1);	
	ListNode* h2 = new ListNode(1);
	ListNode* h3 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;


	Solution s;
	ListNode * res;
	res= s.deleteDuplicates(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}