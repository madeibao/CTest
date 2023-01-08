

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode{ 

	int val;
	ListNode* next;
	ListNode(int v):val(v) {next = NULL; }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        //finding middle point
        //利用快慢指针找到中心点
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reversing the last half
        //将后半部分反转
        auto tail = reverseList(slow->next);
        slow->next = NULL;

        //inseting the last half to the first half
        //将后半部分插入前半段
        auto headptr = head, tailptr = tail;
        while(tailptr)
        {
            auto temp1 = headptr->next;
            auto temp2 = tailptr->next;
            headptr->next = tailptr;
            tailptr->next = temp1;
            headptr = temp1;
            tailptr = temp2;
        }
    }

    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        ListNode* thisNode = head;
        ListNode* last = NULL;
        while(thisNode)
        {
            ListNode* temp = thisNode->next;
            thisNode->next = last;
            last = thisNode;
            thisNode = temp;
        }
        return last;
    }
};


int main(int argc, char* argv[]) {

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

	Solution s;
    s.reorderList(head);
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
	return 0;
}
