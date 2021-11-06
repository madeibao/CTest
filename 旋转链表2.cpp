
#include"iostream"
#include"bits/stdc++.h"

using namespace std;
class Solution {
public:
    ListNode* rotate(ListNode*head, int k) {
        if(k<=0) {return nullptr;}

        auto p = head;
        int n = 0;
        while(p!=nullptr) {
            p = p->next;
            n++;
        }
        k = k%n;
        ListNode* fast= head, *slow = head;

        // 链表的指针向右面移动
        while(k--) {
            fast = fast->next;
        }

        while(fast->next!=nullptr) {
            fast= fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
}

int main(int argc, char*argv[]) {
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k = 2;
    Solution s;
    ListNode* res;
    res = s.rotateRight(head, k);
    while(res!=nullptr) {
        cout <<res->val<<" ";
        res= res->next;
    }
    return 0;
}
