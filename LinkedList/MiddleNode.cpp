

// 链表的中间节点

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

	
/**
	则slow此时为链表的中间节点,此时当链表长度为偶数时，slow指针指向中间两个节点中的靠后节点
*/

ListNode* split(ListNode* head) {
	ListNode*fast=head,*slow=head;
	while(fast!=NULL&&fast->next!=NULL) {
	  fast=fast->next->next;
	  slow=slow->next;
	}

	return slow;
}

// 若是让fast指针指向头节点head->next,此时当链表长度为偶数时指向链表中间节点靠前那个
ListNode* split2(ListNode* head) {
	ListNode*fast=head->next,*slow=head;
	while(fast!=NULL&&fast->next!=NULL) { 
	  fast=fast->next->next;
	  slow=slow->next;
	}
}



int main() {
	ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


  	ListNode* res = split2(head);
  	while(res) {
  		cout << res->val<<" ";
  		res =res->next;
  	}

	return 0;
}