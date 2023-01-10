

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
    ListNode* removeElements(ListNode* head, int val) {
 		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode *pre = dummy;
		ListNode *p = head;

		// 通过给定的指针来逐渐的移动。
		while (pre->next!=nullptr) {
            if(pre->next->val==val) {
                pre->next= pre->next->next;
            }
            else {
                pre = pre->next;
            }
		}
		return dummy->next;
	}

};


int main(int argc, char* argv[]) {
	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;

	int val = 3;

	Solution s;
	ListNode *res;
	res= s.removeElements(head, val);
	while(res!=nullptr) {
		cout<<res->val<<" "<<endl;
		res =res->next;
	}

	return 0;
}
