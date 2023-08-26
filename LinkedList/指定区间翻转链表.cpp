


#include "iostream"
#include "bits/stdc++.h"

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
	ListNode* reverseBetween(ListNode* head, int left, int right) {

		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;

		dummy->next = head;

		ListNode* curr = head;

		for(int i=0;i<left-1;i++) {
			pre = pre->next;
			curr = curr->next;
		}

		for(int i=0;i<right-left;i++) {
			ListNode* temp = curr->next;
			curr->next = temp->next;
			temp->next = pre->next;
			pre->next = temp;
		}

		return dummy->next;
	}

};


int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr;

    int m = 3, n=5;

    ListNode* res;
    Solution s2;
    res = s2.reverse(head, m, n);
    while (res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }   

}
