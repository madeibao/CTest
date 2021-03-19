


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0), p = dummy;  //定义一个新链表，p表示链表尾结点

        int t = 0;                                //t用于每位相加计数及进位
        while (l1 || l2)
        {
            if (l1 && l2) t += l1->val + l2->val; //两个链表都不为空的情况
            else if (l1) t += l1->val;            //两个链表其一为空的情况
            else t += l2->val;

            p = p->next = new ListNode(t % 10);   //两个节点和
            t /= 10;                              //两个数相加最大18，有进位t就等于1，没进位t就置0

            if (l1) l1 = l1->next;                //推进两个链表
            if (l2) l2 = l2->next;
        }

        
        if (t) p->next = new ListNode(1);         //最后一位有进位，则在链表尾部加值为1的新节点

        return dummy->next;
    }
};

int main(){

    ListNode* a = new ListNode(2);
    ListNode* a2 = new ListNode(4);
    ListNode* a3 = new ListNode(3);

    a->next = a2;
    a2->next =a3;
    a3->next = nullptr;


    ListNode* b = new ListNode(5);
    ListNode* b2 =new ListNode(6);
    ListNode* b3 =new ListNode(4);

    b->next = b2;
    b2->next = b3;
    b3->next = nullptr;

    Solution s;
    ListNode* res;
    res= s.addTwoNumbers(a, b);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}

