

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		ListNode* dummy = new ListNode(-1);

		ListNode* p = head;
		while (p) {
			head = head->next;
			p->next = dummy->next;
			dummy->next=p;
			p = head;
		}

		return dummy->next;
	}
};


int main() {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr;

    Solution s;
    ListNode* res = s.reverseList(head);
    while(res!=nullptr) {
        cout<<res->val<< " ";
        res= res->next;
    }
    return 0;
}
