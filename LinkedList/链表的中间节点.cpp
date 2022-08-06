
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) : val(val){}
	ListNode(int v, ListNode* next): val(v), next(nullptr)	 {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}

    	ListNode *fast= head;
    	ListNode *slow= head;

    	while(fast!=nullptr&&fast->next!=nullptr) {
    		fast= fast->next->next;
    		slow= slow->next;
    	}

    	ListNode* res= slow->next;
        slow->next= nullptr;
    	return res;
    }
};

int main(int argc, char* argv[]) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(3);
    ListNode* h5 = new ListNode(5);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = nullptr;

	Solution s;
	ListNode * res;
	res= s.middleNode(head);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}
