
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
	ListNode(int v)	:val(v),next(nullptr){}

};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

    	ListNode* p1 = pHead1;
    	ListNode* p2 = pHead2;

    	while(p1!=p2) {
    		p1 = p1==nullptr ?pHead2:p1->next;
    		p2 = p2==nullptr ?pHead1:p2->next;

    	}
    	return p1;
    }
};


int main() {


	ListNode* h1 = new ListNode(1);
	ListNode* h2 = new ListNode(2);

	ListNode* m2 = new ListNode(1);

	ListNode* common = new ListNode(3);

	h1->next = h2;
	h2->next = common;
	m2->next = common;

	Solution s;
	ListNode * res;
	res = s.FindFirstCommonNode(h1, m2);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}
