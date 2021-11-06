

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

    	ListNode* pre = nullptr;
    	while (pHead!=nullptr) {

    		ListNode* temp = pHead->next;
    		pHead->next = pre;
    		pre = pHead;
    		pHead = temp;
    	}
    	return pre;
    }
};


void travel(ListNode* head) {

	while (head!=nullptr) {
		cout<<head->val<<" ";
		head= head->next;
	}
}


int main(int argc, char* argv[]) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	Solution s;
	ListNode * res = s.ReverseList(head);
	travel(res);

	return 0;
}
