

// 双指针的写法来实现链表的倒数的节点


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr) {}
	ListNode(int v, ListNode* next): val(v), next(nullptr) {}
};


class Solution {
public:
	ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        
        ListNode *quick, *slow;
        quick = slow = pHead;
        while(k > 0 && quick != nullptr)
        {
            quick = quick->next;
            k--;
        }
        if(k > 0)
            return nullptr;
        while(quick != nullptr)
        {
            slow = slow->next;
            quick = quick->next;
        }
        // slow->next = nullptr;  // 题目说是倒数第K个节点。但是不注释这行代码，则得到有K个点的链表。但是正确答案却是需要注释这一行。
        return slow;
    }

};


int main(int argc, char** argv) {


	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h33 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h44 = new ListNode(4);
	ListNode* h5 = new ListNode(5);


	head->next =h2;
	h2->next = h3;
	h3->next = h33;
	h33->next = h4;
	h4->next = h44;
	h44->next = h5;
    h5->next= nullptr;


	Solution s;
	ListNode* res;

	res = s.FindKthToTail(head,2);

	while(res!=nullptr) {
		cout<<res->val<<" ";
		res= res->next;
	}
	return 0;
}
