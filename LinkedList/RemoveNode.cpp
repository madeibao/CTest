

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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* dummy = new ListNode(-1);
    	dummy->next = head;

    	ListNode* pre = dummy;

    	while (pre->next!=nullptr) {
    		if(pre->next->val==val) {
    			pre->next = pre->next->next;
    		}
    		else {
    			pre = pre->next;
    		}
    	}

    	return dummy->next;
    }

};


int main(int argc, char *argv[]) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(6);
    ListNode *n5 = new ListNode(4);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k = 6;

    Solution s;
    ListNode * res = s.removeElements(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;
}
