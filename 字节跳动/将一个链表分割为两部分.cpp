

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr){}
};

class Solution {
	public:
		void split(ListNode* head) {

			if(head==nullptr||head->next==nullptr) {
                travel(head);
				return;
			}

			ListNode* pre= head;
			ListNode* slow = head, *fast = head;
			while(fast!=nullptr&&fast->next!=nullptr) {
				pre = slow;
				slow = slow->next;
				fast = fast->next->next;
			}

		    pre->next = nullptr;

		    travel(head);
		    cout<<endl;
		    travel(slow);
		}

		void travel(ListNode* head) {

			if(head==nullptr||head->next==nullptr) {
				return;
			}
			ListNode* pre=head;
			while(pre!=nullptr) {
				cout<<pre->val<<" ";
				pre = pre->next;
			}
		}
};


int main(int argc, char** argv) {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;


	Solution s;
	s.split(head);


	return 0;
}
