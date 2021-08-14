

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
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here

    	if(k==0) {
    		return head;
    	}

    	ListNode* cur = head;
    	for(int i=0; i<k; i++) {
            // 对于不足k个的情况内容
    		if(!cur) {
    			return head;
    		}
    		cur = cur->next;
    	}

    	ListNode* newHead = helper(head,cur);
    	head->next = reverseKGroup(cur, k);
    	return newHead;

    }

    // 这里的链表是一个左面闭合，右面分开的区间。
    ListNode* helper(ListNode* head, ListNode* tail) {

    	ListNode* pre=nullptr;
    	while(head!=tail) {
    		ListNode* temp = head->next;
    		head->next = pre;
    		pre = head;
    		head = temp;

    	}
    	return pre;
    }
};



int main() {
    Solution s;
    ListNode* res=nullptr;

    ListNode* head= new ListNode(1);
    ListNode* h2= new ListNode(2);
    ListNode* h3= new ListNode(3);
    ListNode* h4= new ListNode(4);
    ListNode* h5= new ListNode(5);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = nullptr;

    res = s.reverseKGroup(head, 2);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }

}


