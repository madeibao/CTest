

// 1 2 3
// 4 5 6

// 1 4 2 5 3 6


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
    void merge(ListNode* headA, ListNode* headB) {
        ListNode* left;
        ListNode* right;

        while(headA!=nullptr&&headB!=nullptr) {

            left = headA->next;
            right= headB->next;

            headA->next= headB;
            headB->next = left;

            headA = left;
            headB = right;
        }
    }
};


int main(int argc, char** argv ) {
	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;


	ListNode *ma = new ListNode(4);
	ListNode *mb = new ListNode(5);
	ListNode *mc = new ListNode(6);

	ma->next = mb;
	mb->next = mc;
	mc->next = nullptr;

	Solution s;
	ListNode * res;

    s.merge(head, ma);
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
	return 0;
}
