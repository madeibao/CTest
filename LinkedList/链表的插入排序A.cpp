

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode* next;
    ListNode(int v):val(v){};
    ListNode(int v, ListNode*next):val(v),next(nullptr) {};
};

class Solution {
public:
    ListNode* insertNode(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;

        // 后续节点不为空
        while(cur!=nullptr) {

   			// 后一个结点小于前一个节点
            if(cur->val<pre->val) {
                ListNode* temp = dummy;
                while(temp->next->val<cur->val) {
                    temp = temp->next;
                }
                pre->next = cur->next;
                cur->next = temp->next;
                temp->next = cur;
                cur = pre->next;
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;

        return head;
    }
};


int main(int argc, char* argv[]) {

    ListNode *head = new ListNode(1);
    ListNode *h2 = new ListNode(4);
    ListNode *h3 = new ListNode(3);
    ListNode *h4 = new ListNode(2);
    ListNode *h5 = new ListNode(5);
    ListNode *h6 = new ListNode(2);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = nullptr;

    Solution s;
    ListNode *res;
    res = s.insertNode(head);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }

    return 0;
}
