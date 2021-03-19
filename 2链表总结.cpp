
// k 个一组来进行链表的翻转。

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

class Solution {
public:
    ListNode* reverseKGroup(ListNode*root, int k) {
        ListNode* tail = root;

        for(int i=0;i<k;i++) {
            if(!tail){
                return root;
            }
            tail = tail->next;
        }

        ListNode* dummyNode = helper(root, tail);
        root->next = reverseKGroup(tail, k);
        return dummyNode;
    }

    ListNode* helper(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;

        while(head!=tail) {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};

int main(int argc, char** argv) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;

    int k(2);

    Solution s;
    ListNode * res = s.reverseKGroup(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;

}

