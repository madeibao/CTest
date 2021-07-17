
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr){}

};


class Solution {
public:
    /**
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* succ = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = succ;
        }
        return prev;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here

        head1 = reverse(head1);
        head2 = reverse(head2);

        ListNode* dummy = new ListNode(-1);
        dummy->next= nullptr;

        ListNode* point = dummy;

        int carry = 0;
        while(head1||head2) {

            int val1 = head1==nullptr?0:head1->val;
            int val2 = head2==nullptr?0:head2->val;

            int value = val1+val2+carry;
            ListNode* temp = new ListNode(value%10);

            point->next = temp;
            point = point->next;
            carry = value/10;

            head1 = head1==nullptr?nullptr:head1->next;
            head2 = head2==nullptr?nullptr:head2->next;
        }
        if(carry>0) {
            point->next = new ListNode(carry);
        }

        return reverse(dummy->next);

    }
};

int main() {
    Solution s;
    ListNode* res=nullptr;

    ListNode* head= new ListNode(1);
    ListNode* h2= new ListNode(2);
    ListNode* h3= new ListNode(3);

    head->next = h2;
    h2->next = h3;
    h3->next = nullptr;

    ListNode* m = new ListNode(1);
    ListNode* m2 =new ListNode(2);
    ListNode* m3 =new ListNode(3);

    m->next = m2;
    m2->next = m3;
    m3->next = nullptr;

    res = s.addInList(head, m);
    while(res){
        cout<<res->val;
        res =res->next;
    }

    return 0;
}


