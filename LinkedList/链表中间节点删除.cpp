
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL||head->next==nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
		ListNode* fast=  head->next;

		while (fast->next!=nullptr && fast->next->next!=nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

        slow->next = slow->next->next;

        return head;
    }
};


int main(int argc, char** argv) {

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(4);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(6);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

	Solution s2;
	ListNode* res;
	res =s2.deleteMiddle(head);
	while (res) {
		cout << res->val << endl;
		res	= res->next;
	}

	return 0;
}
