

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

        ListNode *pa,*pb,*res;
        ListNode* dummy = new ListNode(-1);
        res = dummy;
        pa = l1;
        pb = l2;
        int carry = 0;
        while(pa||pb||carry) {
            int pav = pa?pa->val:0;
            int pbv = pb?pb->val:0;
            int temp = pav+pbv+carry;
            ListNode* node = new ListNode(temp%10);
            res->next = node;
            carry = temp/10;
            res = res->next;
            if(pa)pa= pa->next;
            if(pb)pb= pb->next;
        }

        if(carry!=0) {
            res->next= new ListNode(1);
        }

        return dummy->next;
    }
};


int main() {

    return 0;
}