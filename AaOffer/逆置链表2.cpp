

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* pre= nullptr;

    	while(head) {
    		ListNode* temp = head->next;
    		head->next = pre;
    		pre = head;
    		head = temp;
    	}

    	return pre;
    }
};

int main() {
    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(3);
    ListNode *n4 =new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
	Solution s2;

	ListNode* res;
	res = s2.reverseList(n1);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}
