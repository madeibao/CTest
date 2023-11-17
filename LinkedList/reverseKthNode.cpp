

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = head;
        ListNode* p = head;

        while(n-->0) {
            p = p->next;
        }
        if(!p) {
            return head->next;
        }
        if(p!=nullptr) {
             while(p->next!=nullptr) {
                pre = pre->next;
                p = p->next;
            }
        }

        pre->next = pre->next->next;
        return dummy->next;

    }
};

int main(int argc, char *argv[]) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k(2);

    Solution s;
    ListNode * res = s.removeNthFromEnd(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;
}
