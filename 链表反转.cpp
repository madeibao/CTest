

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val){}
	ListNode(int val, ListNode* next) : val(val),next(nullptr) {}
};

class Solution {
public:
	ListNode* reverse(ListNode* head) {

		ListNode* pre=nullptr;

		while(head!=nullptr){

			ListNode* temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}

		return pre;
	}

};


int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next =nullptr;


	ListNode* res;
	Solution s;
	res = s.reverse(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}