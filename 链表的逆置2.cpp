


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = NULL;
        while(head!=NULL){

            ListNode* result = new ListNode(head->val);
            result->next = first;
            first = result;
            head = head->next;

        }
        return first;
    }
};


int main(int argc, char* argv) {

    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(3);
    ListNode *n4 =new ListNode(4);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    Solution  s;
    ListNode *res =  s.reverseList(n1);
    while (res!=nullptr) {

        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;

}










