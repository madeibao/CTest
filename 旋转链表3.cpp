
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr){}
};

class Solution {
    public:
	ListNode* rotate(ListNode* head, int k) {
		if(head==nullptr) return head;

		ListNode *fast= head;
		ListNode *slow= head;

		ListNode *p = head;
		int temp =0;
		while(p->next!=nullptr) {
			temp++;
			p = p->next;
		}

		k = k%temp;
		while(k--) {
			fast= fast->next;
		}

        while(fast->next!=nullptr) {
            fast= fast->next;
            slow= slow->next;
        }

        // 旋转链表的精髓，指针指向的位置改变。
		fast->next = head;
		head= slow->next;
		slow->next = nullptr;
		return head;
	}
};


int main(int argc, char **argv) {

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode *h4 = new ListNode(4);
	ListNode *h5 = new ListNode(5);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = nullptr;

	int k = 2;
	Solution s;
	ListNode* res;
	res= s.rotate(head, k);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}

	return 0;
}
