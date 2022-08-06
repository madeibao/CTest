
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode *dummA = new ListNode(-1);
    	ListNode *dummB = new ListNode(-1);

    	ListNode *pa= dummA;
    	ListNode *pb= dummB;

    	while(head!=nullptr) {
    		if(head->val<x) {
    			pa->next = head;
    			pa = pa->next;
    		}
    		else {
    			pb->next = head;
    			pb = pb->next;
    		}
    		head = head->next;
    	}

    	pa->next = dummB->next;
    	pb->next = nullptr;
    	return dummA->next;
    }
};

int main(int argc, char **argv) {


	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(4);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(2);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

	int val(3);

	ListNode *res;
	Solution s;
	res = s.partition(head, val);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}
