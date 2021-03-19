
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {

    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL||head->next==NULL) {
        	return head;
        }
        ListNode *ptr=head;
        if(ptr->val!=ptr->next->val) {
            ptr->next=deleteDuplicates(ptr->next);
            return ptr;
        }

        while(ptr!=NULL&&ptr->next!=NULL&&ptr->val==ptr->next->val)
            ptr=ptr->next;
        if(ptr==NULL||ptr->next==NULL) {
        	return NULL;
        } 

        // 删除链表的重复的节点。
        return deleteDuplicates(ptr->next);
    }
};


int main() {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(1);
    ListNode* h3 = new ListNode(2);

    head->next = h2;
    h2->next = h3;
    h3->next = nullptr;

    Solution s;
    ListNode* res;
    res = s.deleteDuplicates(head);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }

    return 0;
}
