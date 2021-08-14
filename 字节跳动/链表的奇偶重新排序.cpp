

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* odd = head, *even = head->next;
        ListNode* evenhead = even;


        while(even != NULL && even->next != NULL) {
            odd->next  = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even= even->next;

        }
        odd->next = evenhead;
        return head;
    }
};


int main(int argc, char* argv []) {


    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);
    ListNode* h5 = new ListNode(5);
    ListNode* h6 = new ListNode(6);

    head->next  = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = nullptr;

    Solution s;
    ListNode * res  = s.oddEvenList(head);
    while (res!=nullptr) {
        cout<<res->val<<" ";
        res =res ->next;
    }

    return 0;
}
