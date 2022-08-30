
//  两个，两个来交换链表中的相邻的节点。
//  相邻节点的交换。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};


class Solution {
public:
    ListNode* exchangeNode(ListNode* head) {

    	// 跳出递归的条件必须有。
        // 递归必须有结束的条件。
        if(head==nullptr||head->next==nullptr) {
            return head;
        }
        ListNode* temp = head->next;
        ListNode* temp2 = exchangeNode(temp->next);
        temp->next = head;
        head->next = temp2;
        return temp;
    }
};


int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    Solution s;

    ListNode *temp = s.exchangeNode(n1);
    while(temp) {
        cout<<temp->val<<"->";
        temp= temp->next;
    }
    return 0;
}

