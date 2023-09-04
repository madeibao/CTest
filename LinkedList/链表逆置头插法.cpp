
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *ReverseList1(ListNode *pHead)//头插法（改变链表结构）  
{  
	if(pHead==NULL)  
		return NULL;  
	ListNode *p=pHead->next;  
	ListNode *newHead=pHead;  
	while(p!=NULL)         //将p结点移到链表最前方  
	{         
		pHead->next=p->next;//头结点指向p的下一个结点  
		p->next=newHead; //p插入链表最前方  
		newHead=p;      //链表新头结点更新为p  
		p=pHead->next;//处理下一个结点，该结点位于头结点后  
	}  
	return newHead;  
}


int main() {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr;

    Solution s;
    ListNode* res = s.reverseList(head);
    while(res!=nullptr) {
        cout<<res->val<< " ";
        res= res->next;
    }
    return 0;
}
