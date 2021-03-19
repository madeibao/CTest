
// 链表的指定的区间来翻转。


#include<iostream>
#include<bits/stdc++.h>

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr){}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode L = ListNode(0);
        L.next = head;
        ListNode* p = &L;
        ListNode* q = head;
        for (int i = 1; i < m; i++) {
            p = q;
            q = q->next;
        }


        for (int i = 0; i < n-m; i++) {
            ListNode* t = q->next;
            q->next = t->next;
            t->next = p->next;
            p->next = t;
        }
        return L.next;
    }
};


int main(int argc, char* argv[]) {


	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h5 = new ListNode(5);


	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = nullptr;

	ListNode* res;
	Solution s;
	res = s.reverseBetween(head,2,4);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}

	return 0;
}