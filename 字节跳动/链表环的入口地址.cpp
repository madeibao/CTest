

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode*fast=pHead,*low=pHead;
        while(fast&&fast->next) {
            fast=fast->next->next;
            low=low->next;
            if(fast==low)
                break;
        }
        if(!fast||!fast->next)return NULL;
        low=pHead;//low从链表头出发
        while(fast!=low){//fast从相遇点出发
            fast=fast->next;
            low=low->next;
        }
        return low;
    }
};



int main(int argc, char* argv[])  {

    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;

    Solution s;

    ListNode* res;
    res= s.EntryNodeOfLoop(head);
    cout<<res->val<<" ";
    return 0;
}


