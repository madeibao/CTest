
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};


ListNode* reverse(ListNode *head) {

	ListNode* new_head = nullptr;
	ListNode* temp = nullptr;

	if(head==nullptr||head->next==nullptr) {
		return head;
	}

	while(head!=nullptr) {
		temp = head;
		head = head->next;
		temp->next= new_head;
		new_head = temp;
	}

	return new_head;

}

// 打印链表
void printNode(ListNode *head) {
	while(head!= nullptr) {
		cout<<head->val<<"->";
		head= head->next;
	}
}


int main(int argc, char *argv[]) {
	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(6);
	ListNode *n7 = new ListNode(7);

	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = nullptr;

	printNode(head);

	cout<<endl<<"********************************"<<endl;
	ListNode* res = reverse(head);

	printNode(res);

}
