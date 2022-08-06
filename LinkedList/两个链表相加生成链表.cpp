
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr) {}
};

class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here

        stack<int> sa;
        stack<int> sb;

        while(head1) {
        	sa.push(head1->val);
        	head1 = head1->next;
        }

        while(head2) {
        	sb.push(head2->val);
        	head2 = head2->next;
        }

        ListNode* res=nullptr;
        int carry = 0;

        while((!sa.empty())||(!sb.empty())||(carry>0)) {
        	int a = sa.empty()?0:sa.top(); sa.pop();
        	int b = sb.empty()?0:sb.top(); sb.pop();

        	int temp= a+b+carry;
        	ListNode* node = new ListNode(temp%10);
        	node->next = res;
        	res =node;
        	carry = temp / 10;
        }
        return res;
    }
};

int main(){

    ListNode* a = new ListNode(1);
    ListNode* a2 = new ListNode(9);

    a->next = a2;
    a2->next =nullptr;

    ListNode* b = new ListNode(2);
    ListNode* b2 =new ListNode(1);
    b->next = b2;
    b2->next = nullptr;

    Solution s;
    ListNode* res;
    res= s.addInList(a, b);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}




