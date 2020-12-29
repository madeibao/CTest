



// 两个有序的链表来进行合并。
// #--------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};


class Solution{
public:
    ListNode* mergeNode(ListNode* h1, ListNode* h2) {
        ListNode* h;

        if(h1==nullptr) return h2;
        if(h2==nullptr) return h1;

            if(h1->val<h2->val) {
                h = h1;
                h->next  = mergeNode(h1->next, h2);
            }
            else {
                h = h2;
                h->next = mergeNode(h1, h2->next);
            }
        return h;
    }

};


int main() {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    h1->next = h2;
    h2->next = nullptr;

    ListNode* m1 = new ListNode(3);
    ListNode* m2 = new ListNode(4);
    m1->next = m2;
    m2->next =nullptr;

    ListNode* res;
    Solution s;
    res = s.mergeNode(h1, m1);

    while(res!=nullptr) {
        cout<<res->val<<" ";
        res = res->next;
    }

}
