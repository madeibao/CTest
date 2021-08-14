
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
    void reorderList(ListNode* head) {

 		if(head == nullptr) {
 			return;
 		}

 		ListNode *left;
 		ListNode *right;
 		ListNode *res = middle(head);

 		left = head;
 		right = res->next;

 		// 断链的操作，
 		res->next = nullptr;
 		
 		// 将右面的内容来进行逆置操作。
    	ListNode *res2 = reverse(right);
    	merge(left, res2);
    }
    // 求链表的中间节点内容
    ListNode* middle(ListNode *head) {

    	ListNode *fast = head;
    	ListNode *slow = head;

    	while(fast!=nullptr&&fast->next!=nullptr) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	return slow;
    }

    // 链表的翻转操作。
    ListNode *reverse(ListNode *head) {
    	ListNode *pre=nullptr;
    	while(head!=nullptr) {
    		ListNode *node = head->next;
    		head->next = pre;
    		pre= head;
    		head = node;
    	}
    	return pre;
    }

    // 两个链表的归并操作
    void merge(ListNode* headA, ListNode* headB) {

    	ListNode *left;
    	ListNode *right;

    	while(headA->next!=nullptr&&headB!=nullptr) {

    		left = headA->next;
    		right = headB->next;

    		headA->next = headB;
    		headB->next = left;
    		headA = left;
    		headB = right;
    	}
    }
};


int main(int argc, char* argv[]) {

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

	Solution s;
    s.reorderList(head);
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
	return 0;
}
