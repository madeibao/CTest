
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v)	:val(v),next(nullptr) {}
};


class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = dummy;
        ListNode* q = head;

        int step = 0;
        while(step <m-1) {
        	p = p->next;
        	q = q->next;
        	step++;
        }

        // p指向的是要翻转节点的前面一个节点，
        // q指向的是第一个要翻转的节点。
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
