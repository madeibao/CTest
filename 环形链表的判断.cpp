
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr) {}
    ListNode(int v, ListNode* next): val(v), next(nullptr) {}
};

class Solution {
public:
    bool isCycle(ListNode* head) {
        if(head==nullptr) {
            return false;
        }

        ListNode* slow = head, *fast = head;
        while(fast!=nullptr&&fast->next!=nullptr) {
            fast= fast->next->next;
            slow= slow->next;
            if(fast==slow) {
                return true;
            }
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
    cout<<s.isCycle(head)<<endl;
    return 0;
}


