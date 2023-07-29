
// 实现单链表的逆置的操作。
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode  {
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummyNode = new ListNode(-1),h = dummyNode;
        dummyNode->next = head;

        for(int i = 0; i < left - 1; i++, h = h->next);

        auto p = h->next;
        for(int i = 0; i < right - left; i++){
            auto q = p->next;
            p->next = q->next;
            q->next = h->next;
            h->next = q;
        }

        return dummyNode->next;
    }
};

*/


class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {

		if(head==nullptr||head->next ==nullptr) {
			return head;
		}
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode* q = head;


        for(int i = 0; i <left-1; i++) {
            pre = pre->next;
            q = q->next;
        }

        // cout<<pre->val<<"  "<<q->val<<endl;

        // pre 要反转的前面节点
        // q 节点第一个要反转节点

        // 反转次数
        for(int i=left;i<right;i++) {
        	ListNode* temp = q->next;
        	q->next = temp->next;
        	temp->next = pre->next;
        	pre->next = temp;

        }

        return dummy->next;
    }

};


int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    Solution s;

   	int left(2), right(4);
   	ListNode *res;
   	res = s.reverseBetween(n1, left, right);
   	while(res!=nullptr) {
   		cout<<res->val<<" ";
   		res =res->next;
   	}


	return 0;
}
