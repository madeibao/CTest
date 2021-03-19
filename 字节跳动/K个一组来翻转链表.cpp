
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
	// 翻转的是一个前面闭区间，后面开区间的一个算法值。
    ListNode* reverse(ListNode* head,ListNode* tail) {
        ListNode* pre = nullptr;
        while(head != tail)  {
            ListNode* nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }

    //分组
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0;i < k;i++){
            //不足k个不用翻转
            if(cur == nullptr) return head;
            cur = cur->next;
        }

        //新的头变成翻转后的返回值
        // 返回的链表的节点的值。
        ListNode* newhead = reverse(head,cur);
        //旧的头变成了尾，应该连接原来还没翻转的链表

        // 递归的遍历翻转。
        head->next = reverseKGroup(cur,k);
        return newhead;
    }
};




int main() {
    Solution s;
    ListNode* res=nullptr;

    ListNode* head= new ListNode(1);
    ListNode* h2= new ListNode(2);
    ListNode* h3= new ListNode(3);
    ListNode* h4= new ListNode(4);
    ListNode* h5= new ListNode(5);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = nullptr;

    res = s.reverseKGroup(head, 2);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }


}



