

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

// 双指针的方法来实现链表的翻转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
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
