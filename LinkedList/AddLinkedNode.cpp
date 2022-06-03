
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // 表示进位，再加一
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};




int main(int argc, char ** argv) {



	ListNode* head = new ListNode(2);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(3);


    head->next = n2;
    n2->next = n3;
    n3->next = nullptr;


	ListNode* ma = new ListNode(5);
    ListNode* mb = new ListNode(6);
    ListNode* mc = new ListNode(4);

    ma->next = mb;
    mb->next = mc;
    mc->next = nullptr;


    Solution s;
    ListNode* res;
    res = s.addTwoNumbers(head, ma);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }

	return 0;
}