
// 重复出现的节点都会删除。
// 删除链表中，所有的重复节点。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val),next(nullptr) {}
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here

    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}
    	// 首先建立一个虚拟的节点值。
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;

        while (cur!=nullptr&&cur->next!=nullptr) {
        	if(cur->val!=cur->next->val) {
        		pre = cur;
        	}

        	else {
        		while(cur->next!=nullptr&&cur->val==cur->next->val) {
        			cur= cur->next;
        		}
        		pre->next = cur->next;
        	}
        	cur =cur->next;
        }

        return dummy->next;
    }
};

int main(int argc, char* argv[]) {


	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;


	ListNode* res;
	Solution s;
	res = s.deleteDuplicates(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}



