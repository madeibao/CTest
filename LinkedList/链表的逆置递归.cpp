

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head==nullptr||head->next==nullptr) {
            return head;
        }
        ListNode* temp = head->next;
        ListNode* res = reverse(temp);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};

int main(int argc, char* argv[]) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    Solution s;
    ListNode* res;
    res = s.reverse(n1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
