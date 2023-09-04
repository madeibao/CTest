

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* workptr = head;
        ListNode* nummy = new ListNode(-1);
        nummy->next = nullptr;

        while(head){
            head = head->next;
            workptr->next = nummy->next;
            nummy->next = workptr;
            workptr = head;
        }
        head = nummy->next;
        delete nummy;
        return head;
    }
};


int main() {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr;

    Solution s;
    ListNode* res = s.reverseList(head);
    while(res!=nullptr) {
        cout<<res->val<< " ";
        res= res->next;
    }
    return 0;
}
