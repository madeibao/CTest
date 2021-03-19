
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(k-->0) {
            fast= fast->next;
        }

        while(fast!=nullptr&&fast->next!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};


int main(int argc, char** argv) {

    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(4);
    ListNode* n6 = new ListNode(5);

    n2->next =n3;
    n3->next =n4;
    n4->next =n5;
    n5->next =n6;
    n6->next =nullptr;

    int k =2;
    Solution s;
    ListNode* res=  s.getKthFromEnd(n2, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }

    return 0;
}
