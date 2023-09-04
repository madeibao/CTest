

#include "iostream"
#include "bits/stdc++.h"

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
    ListNode* reverse(ListNode* head) const {    

        ListNode* pre =nullptr;

        while(head) {

            ListNode* temp = head->next;
            
        }


    }
};

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr;

    int m = 3, n=5;

    ListNode* res;
    Solution s2;
    res = s2.reverse(head, n6);
    while (res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }   

}
