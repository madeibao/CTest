
//----------------------------------------------------------------
//删除链表的节点

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v) {}
	ListNode(int v, ListNode* next):val(v),next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* node,int val) {

        ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		pre->next = node;

		ListNode* p = node;

        while(p->val!=val) {
            pre = p;
            p = pre->next;
		}

		pre->next = p->next;

		return dummy->next;
	}

};


int main(int argc, char** argv) {
    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(3);
    ListNode *n4 =new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    Solution s;

    int v(3);

    ListNode *res;
    res = s.deleteNode(n1,v);
    while(res) {
    	cout<<res->val<<" ";
    	res =res->next;
    }

	return 0;
}
