
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* exchangeNode(ListNode* head) {
		// 递归一定有结束的条件。
		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		ListNode* temp = head->next;
		ListNode* temp2 = exchangeNode(temp->next);

		temp->next = head;
		head->next = temp2;
		return temp;
	}
};


int main(int argc, char** argv) {

	ListNode* head=  new ListNode(1);
	ListNode* n2=  new ListNode(2);
	ListNode* n3=  new ListNode(3);
	ListNode* n4=  new ListNode(4);

	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;

	Solution s;
	ListNode* res;
	res = s.exchangeNode(head);
	while(res!=nullptr) {
		cout<<res->val<<endl;
		res =res->next;
	}

	return 0;
}






