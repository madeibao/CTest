
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v,ListNode* next): val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 移动快指针到正数第 k 个节点
        for(int i = 0;i<k-1;i++){
            fast = fast->next;
        }
        // 让快指针和慢指针同时向前移动，直到快指针到达链表末尾
        ListNode* temp = fast;
        while(temp->next !=nullptr){
            //更新slow、temp
            slow = slow->next;
            temp = temp->next;
        }
        //交换快慢指针所指向节点的值
        swap(slow->val,fast->val);
        return head;
    }
};


int main() {

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(4);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(6);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

    int k = 2;
    Solution s2;

    ListNode* res;
    res = s2.swapNodes(head,k);

    while(res!=nullptr) {
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
