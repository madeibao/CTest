
// 删除链表的倒数的第k个节点。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}

};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;
        while(n-->0) {
            fast= fast->next;
        }

        while(fast->next!=nullptr) {
            fast= fast->next;
            slow= slow->next;
        }
        slow->next = slow->next->next;
        return head;

    }

};


int main(int argc, char* argv[]) {

	ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr;

    int k =2;
    ListNode* res;
    Solution s;
    res = s.removeNthFromEnd(head, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }
    return 0;
}

