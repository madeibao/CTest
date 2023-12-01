

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    ListNode(int v):val(v) {}
    ListNode(int v,ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head;
        while (cur->next != nullptr) {
            ListNode *tmp = new ListNode(gcd(cur->val, cur->next->val), cur->next);
            cur->next = tmp;
            cur = tmp->next;
        }
        return head;
    }
};



int main(int argc, char** argv) {



    return 0;
}