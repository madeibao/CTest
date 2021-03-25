
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr)	{}
};

class Solution {
public:
	ListNode* exchangeNode(ListNode* head) {

		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		ListNode* node = head->next;
		ListNode* tempNode = exchangeNode(node->next);
		head->next = tempNode;
		node->next = head;
		return node;
	}
};

int main(int argc, char* argv[]) {

	ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(9);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


    ListNode* res;
    Solution s;
    res =s.exchangeNode(n1);
    while( res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;
}


