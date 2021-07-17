
// 1 2 3 3 4 4 5

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr) {}
	ListNode(int v, ListNode* next): val(v), next(nullptr) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head||!head->next) return head;

    	if(head->val!=head->next->val) {
    		head->next = deleteDuplicates(head->next);
    	}
    	else {
    		ListNode* move = head->next;

    		// 逐渐的向后面移动。
    		while(move&&head->val==move->val) {
    			move = move->next;
    		}

    		return deleteDuplicates(move);
    	}
    	return head;
    }
};

int main(int argc, char* argv[]) {


	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h33 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h44 = new ListNode(4);
	ListNode* h5 = new ListNode(5);


	head->next =h2;
	h2->next = h3;
	h3->next = h33;
	h33->next = h4;
	h4->next = h44;
	h44->next = h5;
    h5->next= nullptr;


	Solution s;
	ListNode* res;

	res = s.deleteDuplicates(head);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}
