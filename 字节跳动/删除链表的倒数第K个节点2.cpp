
// 删除链表的倒数的第k个节点。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr){}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head==nullptr||n<1) {
			return head;
		}

		ListNode* cur = head;

		// 通过一个循环来比较n和链表长度的关系。
		while(cur!=nullptr) {
			n--;
			cur = cur->next;
		}
		
		//
		if(n==0) {
			head = head->next;
		}

		if(n<0) {

			// 重新的指定链表的头节点。
			cur= head;
			while(++n!=0) {
				cur =cur->next;
			}
			cur->next= cur->next->next;
		}
		return head;
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
	int n = 2;

	ListNode* res;
	Solution s;
	res = s.removeNthFromEnd(head, n);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}