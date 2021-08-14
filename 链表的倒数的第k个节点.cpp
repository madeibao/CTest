
// 基于快慢指针来实现
// 删除链表的倒数的第k个节点。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr) {}
	ListNode(int v, ListNode* next): val(v), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here

        ListNode* pre = new ListNode(-1);
       	pre->next = pHead;

       	ListNode* slow= pre;
       	ListNode* fast= pHead;

       	while(k>0) {
       		fast = fast->next;
       		k--;
       	}

       	while(fast!=nullptr&&fast->next!=nullptr) {
       		slow = slow->next;
       		fast = fast->next;
       	}

       	slow->next = slow->next->next;
       	return pre->next;
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
