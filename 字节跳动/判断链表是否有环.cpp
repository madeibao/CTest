

// 判断链表是否有环，是否包含环状的结构。

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
        bool hasCycle(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast!=nullptr&&fast->next!=nullptr) {
                if(fast==slow){return true;}
                fast = fast->next->next;
                slow = slow->next;
            }

            return false;
        }
};


int main() {

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
    cout<<s.hasCycle(head)<<endl;
    return 0;
}


