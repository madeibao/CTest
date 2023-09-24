
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v):val(v){}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {

    	ListNode *fast=  head;
    	ListNode *slow= head;

    	while (k--) {
    		fast = fast->next;
    	}

    	while(fast!=nullptr) {
    		fast= fast->next;
    		slow= slow->next;
    	}

    	return slow->val;
    }
};


int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h5 = new ListNode(5);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = nullptr;

	Solution s;
	int val(2);
	cout<<s.kthToLast(head,val);
	return 0;
}
