




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
    ListNode* deleteDuplicates(ListNode* head) {

    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}

    	if(head->next!=nullptr&&head->val==head->next->val) {
    		while(head->val==head->next->val) {
    			head = head->next;
    		}
    		return deleteDuplicates(head->next);
    	}
    	else {
    		head->next = deleteDuplicates(head->next);
    	}

    	return head;
    }
};

int main(int argc, char *argv[]) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode *n5 = new ListNode(4);
    ListNode *n6 = new ListNode(3);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


    Solution s;
    ListNode * res = s.deleteDuplicates(n1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;
}
