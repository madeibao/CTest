
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int v):val(v) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

    	// 虚拟的头节点值。
        ListNode* dumb = new ListNode(-1);
        dumb->next = head;

        // head是最后一个已经排好序的位置
        // head->next是第一个待排序的位置
        while (head && head->next) {
            if (head->val > head->next->val) {
            	// 从第一个节点的位置来进行遍历
                ListNode* p = dumb;
                while (p->next->val < head->next->val)  {
                	p = p -> next;
                }

                ListNode* cur = head->next;
                head->next = cur->next;
                cur->next = p->next;
                p->next = cur;
            }
            else {
                    head = head->next;
            }
        }

        // 删除虚拟的头指针节点值。
        head = dumb->next;
        delete dumb;
        return head;
    }
};


int main(int argc, char* argv[]){

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(4);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(2);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;

    Solution s;
    ListNode *res;
    res = s.insertionSortList(head);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }

	return 0;
}
