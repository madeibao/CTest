
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode { 
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

  		if(!head) return nullptr;
  		head->next = removeElements(head->next, val);
  		return head->val==val?head->next:head;
    }
};


int main(int argc, char** argv ) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h2 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	int val = 2;
	ListNode* res;
	res = s.deleteDuplicates(head, val);
	while(res!=nullptr) {
		cout<<res->val<<;
		res =res->next;
	}
	return 0;
}