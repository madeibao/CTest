

// 实现单链表的逆置的操作。
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode  {
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* reverse(ListNode* head) {

	if(head==nullptr||head->next==nullptr) {
		return head;
	}

	ListNode* pre= nullptr;

	while(head!=nullptr) {
		ListNode* temp= head->next;
		head->next=pre;
		pre= head;
		head= temp;

	}
	return pre;
}


void printListNode(ListNode* head) {

	if(head == nullptr) {
		return;
	}
	while(head!=nullptr) {
		cout<<head->val<<" ";
		head = head->next;
	}

}
int main(int argc, char* argv[]) {

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;


	ListNode* res = reverse(n1);
	printListNode(res);
	return 0;

}



