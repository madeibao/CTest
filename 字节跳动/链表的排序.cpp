
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
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here

        //首先来将链表一分为二成为两部分。

        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;

        // 归并两个部分的链表。
        return combine(sortInList(head), sortInList(slow));

    }

    // 调用归并排序算法。
    ListNode* combine(ListNode* a, ListNode*b){
        if(!a) {
            return b;
        }

        if(!b){
            return a;
        }

        ListNode* pre=nullptr;
        if(a->val<b->val) {
            pre =a;
            pre->next = combine(a->next, b);
        }
        else {
            pre= b;
            pre->next = combine(a, b->next);
        }
        return pre;
    }
};


int main(int argc, char** argv) {

	ListNode* head= new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(1);

	head->next = n2;
	n2->next  = n3;
	n3->next  = nullptr;

	ListNode* res;
	Solution s;

	res = s.sortInList(head);


	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}
