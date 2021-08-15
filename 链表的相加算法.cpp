

#include "iostream"
#include "bits/stdc++.h"

using namespace std; //
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   	    ListNode* dummy = new ListNode(-1);
    	ListNode* p = dummy;

    	int t =0;
    	while(l1||l2||t) {
    		if(l1!=nullptr) {
    			t += l1->val;
                l1= l1->next;
    		}
    		if(l2!=nullptr) {
    			t+= l2->val;
                l2 = l2->next;
    		}

    		ListNode *temp = new ListNode(t%10);
    		p->next = temp;
    		p = p->next;
    		t = t/10;
    	}

    	return dummy->next;
    }
};

int main(int argc, char* argv[]) {


	ListNode *head = new ListNode(2);
	ListNode *h2 = new ListNode(4);
	ListNode *h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;


	ListNode *ma = new ListNode(5);
	ListNode *mb = new ListNode(6);
	ListNode *mc = new ListNode(4);

	ma->next = mb;
	mb->next = mc;
	mc->next = nullptr;


	Solution s;
	ListNode * res;

	res = s.addTwoNumbers(head, ma);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}
