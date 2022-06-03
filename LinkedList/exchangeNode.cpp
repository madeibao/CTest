

// 链表的两个两个交换

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
	ListNode* exchange(ListNode* head) {

		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		ListNode* temp = head->next;
		ListNode* node = exchange(temp->next);
		head->next = node;
		temp->next = head;

		return temp;

	}
};



int main(int argc, char ** argv) {

    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;

    int k(2);

    Solution s;
    ListNode * res = s.exchange(head);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;

}