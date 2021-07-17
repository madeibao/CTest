
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};

class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here

        if(l1==nullptr) {
            return l2;
        }
        
        if(l2==nullptr) {
            return l1;
        }

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy= new ListNode(-1);
        ListNode* res= dummy;

        while(p1!=nullptr&&p2!=nullptr) {
            if(p1->val<p2->val) {

                res->next = p1;
                p1 = p1->next;
            }
            else {
                res->next = p2;
                p2= p2->next;
            }
            res = res->next;
        }

        if(p1!=nullptr) {
            res->next = p1;
        }
        if(p2!=nullptr) {
            res->next = p2;
        }
        return dummy->next;
    }
};


int main(){

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    n1->next  = n2;
    n2->next  = n3;
    n3->next  = nullptr ;

    ListNode* h1 = new ListNode(2);
    ListNode* h2 = new ListNode(3);
    h1->next = h2;
    h2->next = nullptr;

    Solution s;
    ListNode* res;
    res  = s.mergeTwoLists(n1, h1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }
    return 0;

}
