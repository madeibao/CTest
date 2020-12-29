
// 链表的翻转头插法


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
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
        ListNode* h=NULL;
        while(head) {
           ListNode* p=head;
           head=head->next;
           p->next=h;
           h=p;     
        }
        return h;
    }
};


int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;
    Solution s;

    ListNode *temp = s.reverseList(n1);
    while(temp) {
        cout<<temp->val<<"->";
        temp= temp->next;
    }
    return 0;
}



