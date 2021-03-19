// 将链表的奇偶链表来进行分割。

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int v):val(v),next(nullptr) {}
};

class Solution {
    public:
        ListNode* splitNode(ListNode* head) {
            if(head==nullptr||head->next==nullptr) {
                return head;
            }

            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenhead = even;

            while(even!=nullptr&&even->next!=nullptr) {
                odd->next = odd ->next->next;
                even->next = even ->next->next;
                odd = odd->next;
                even= even->next;
            }

            odd->next = evenhead;
            return head;
        }
};

int main(int argc, char* argv[]) {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);
    ListNode* h5 = new ListNode(5);
    ListNode* h6 = new ListNode(6);

    head->next  = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = nullptr;

    Solution s;
    ListNode * res  = s.splitNode(head);
    while (res!=nullptr) {
        cout<<res->val<<" ";
        res =res ->next;
    }

}

