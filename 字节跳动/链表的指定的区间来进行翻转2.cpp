
// 将链表的一个区间内容来进行翻转。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next; // 
	ListNode(int v):val(v), next(nullptr){}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		// 两个链表的指针指向相差一个位置。
		ListNode* p = dummy;
		ListNode* q = head;

		// 移动节点
		for(int i=0;i<m-1;i++) {
			p = p->next;
			q = q->next;
		}


		// 接下来进行链表的整体的翻转。
		for(int i=0;i<n-m;i++) {
			ListNode* t = q->next;
			q->next = t->next;
			t->next = p->next;
			p->next = t;
		}

		return dummy->next;
	}
};
int main(int argc, char** argv) {

	ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


    int m = 2, n= 4;
    ListNode* res;
    Solution s;
    res = s.reverseBetween(n1, m, n);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }

	return 0;
}
