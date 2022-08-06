

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

    // 是一个前封闭，右面开放的区间。
    // 迭代翻转[head, tail)范围的链表
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* cur;
        while (head != tail) {
            cur = head->next;
            head->next = prev;
            prev = head;
            head = cur;
        }
        return prev;
    }

    // 递归调用reverseKGroup()进行分组
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* dummyhead = head;
        for (int i = 0; i < k; i++) {
            if (!tail) return head;
            tail = tail->next;
        }

        dummyhead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return dummyhead;
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
    ListNode * res = s.reverseKGroup(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;
}


