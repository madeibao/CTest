

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


class Solution {
public:
	ListNode* reverse(ListNode* head) {

		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		ListNode* temp  = head->next;
		ListNode* temp2 = reverse(temp);
		head->next->next= head;
		head->next = nullptr;
		return temp2;

	}
};

int main(int argc, char** argv ) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next =nullptr;

	ListNode* res;
	Solution s;
	res = s.reverse(head);
	while(res!=nullptr) {
		cout<<res->val<<endl;
		res=res->next;
	}

	return 0;
}




