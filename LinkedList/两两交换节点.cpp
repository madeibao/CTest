

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int v):val(v){};
	ListNode(int v, ListNode* next):val(v), next(nullptr){};
};


class Solution {
public:
	ListNode* exchange(ListNode* head){
		if(head==nullptr) {
			return nullptr;
		}

		if(head==nullptr||head->next==nullptr) {
			return head;
		}
		ListNode* temp = head->next;
		ListNode* res = exchange(temp->next);
		head->next= res;
		temp->next= head;
		return temp;
	}
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    Solution s;

    ListNode *temp = s.exchange(n1);
    while(temp) {
        cout<<temp->val<<"->";
        temp= temp->next;
    }
    return 0;
}

