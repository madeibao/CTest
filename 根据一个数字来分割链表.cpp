
// 根据一个数字来分割链表。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr) {}
};


class Solution {
public:
	ListNode* split(ListNode* head, int x) {
		ListNode* pa = new ListNode(-1);
		ListNode* pb = new ListNode(-1);

		// 设置两个临时的指针指向头节点的值。
		ListNode* tempa= pa;
		ListNode* tempb = pb;

		while(head!=nullptr) {
			if(head->val<x) {
				tempa->next = head;
				tempa = tempa->next;
			}
			else {
				tempb->next = head;
				tempb = tempb->next;
			}
			head = head->next;
		}
		
		// 分割链表的值。
		tempa->next = pb->next;
		tempb->next = nullptr;
		return pa->next;
	}
};


int main(int argc, char* argv[]) {


    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(5);

    n2->next =n3;
    n3->next =n4;
    n4->next =n5;
    n5->next =n6;
    n6->next =nullptr;


    Solution s; 
    ListNode * res =  s.split(n2, 2);

    while(res!=nullptr) {
    	cout<<res->val<<endl;	
    	res = res->next;
    }
	return 0;
}
