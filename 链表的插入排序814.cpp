

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v) {}
	ListNode(int v,ListNode* next):val(v),next(nullptr) {}
};

class Solution  {
	public:
		ListNode* insertSort(ListNode* head) {


			// 首先是生成一个节点
			ListNode* dummy = new ListNode(-1);
			dummy->next = head;
			while(head&&head->next) {
				if(head->val>head->next->val) {
                    ListNode *p = dummy;
                    while(p->next->val<head->next->val) {
                        p = p->next;
                    }
                    ListNode *node = head->next;
                    head->next=node->next;
                    node->next = p->next;
                    p->next = node;
				}
				else {
					head = head->next;
				}
			}

			head = dummy->next;
			delete dummy;
			return head;

		}
};

int main(int argc, char* argv[]) {

	ListNode *head = new ListNode(3);
	ListNode *h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(1);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;

	ListNode *res;
	Solution s;
	res =s.insertSort(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res=res->next;
	}
	return 0;
}
