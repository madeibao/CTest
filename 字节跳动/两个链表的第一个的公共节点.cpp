

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1, *p2 = pHead2;

        // 只要没有指向同一个节点的值。
        while (p1 != p2) {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1;
    }
};


int main() {

	ListNode* c2 = new ListNode(4);
	ListNode* c3 = new ListNode(5);
	ListNode* c4 = new ListNode(6);

	c2->next = c3;
	c3->next = c4;
	c4->next = nullptr;


	ListNode* n1 = new ListNode(1);
	n1->next = c2;

	ListNode* h1 = new ListNode(2);
	ListNode* h2 = new ListNode(3);
	ListNode* h3 = new ListNode(4);


	h1->next = h2;
	h2->next = h3;
	h3->next = c2;

	Solution s;
	ListNode* res;
	res= s.FindFirstCommonNode(n1, h1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }

	return 0;
}
