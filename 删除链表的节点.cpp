

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode * head, int x) {
        if(head==nullptr) {
            return nullptr;
        }

        // 如果头节点等于 给定的值。
        if(head->val==x) {
            return head->next;
        }

        ListNode* pre = head;
        while((pre->next)!=nullptr&&pre->next->val!=x) {
            pre =pre->next;

        }

        if(pre->next!=nullptr) {
            pre->next = pre->next->next;
        }
        return head;

    }
};


int main(int argc, char** argv) {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    int x = 2;
    Solution s;

    ListNode* res=  s.deleteNode(n1, x);
    while(res!=nullptr) {
        cout<<res->val<<endl;
        res = res->next;
    }


    return 0;
}





