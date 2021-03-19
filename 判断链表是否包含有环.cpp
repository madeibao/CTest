

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) {
            return false;
        }
        ListNode *first = head;
        ListNode *second = head;

        // 两个快慢指针来实现判断是否有环。
        while(first!=nullptr&&first->next!=nullptr) {
            first= first->next->next;
            second = second->next;
            if(first==second) {
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
    cout<<s.hasCycle(head)<<endl;
    return 0;
}
