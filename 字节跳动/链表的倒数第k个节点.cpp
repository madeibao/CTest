
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v):val(v),next(nullptr) {}
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
     * @param n int整型
     * @return ListNode类
     */

    ListNode* removeNthFromEnd(ListNode* head, int n) {
       	if(n<=0) {return head;}
       	if(head==nullptr||head->next== NULL) {
       		return head;
       	}

       	ListNode* fast = head;
       	ListNode* slow = head;

       	// 快指针先走。
       	while(n-->0) {
       		fast = fast->next;
       	}

       	while(fast!=nullptr&&fast->next!=nullptr) {
       		fast = fast->next;
       		slow = slow->next;
       	}

       	slow->next = slow->next->next;
       	return head;
        // write code here
    }
};


int main(int argc, char* argv[]) {

	ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;


    int n =2;

    ListNode* res;
    Solution s;
    res= s.removeNthFromEnd(n1, n);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;

}
