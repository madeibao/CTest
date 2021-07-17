

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v):val(v),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // 合并两个有序链表
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        }
        else{
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {


    	// 如果数组的长度为0
        if(lists.size() == 0) {
        	return nullptr;
        }
        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); ++i){
            if(lists[i]) head = merge(head, lists[i]);
        }
        return head;
    }
};

int main(int argc, char* argv[])  {

	ListNode* h = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	h->next = h2;
	h2->next = h3;
	h3->next = nullptr;


	ListNode* m = new ListNode(1);
	ListNode* m2 = new ListNode(3);
	ListNode* m3 = new ListNode(4);

	m->next = m2;
	m2->next = m3;
	m3->next = nullptr;


	ListNode* p = new ListNode(2);
	ListNode* p2 = new ListNode(4);
	ListNode* p3 = new ListNode(8);

	p->next = p2;
	p2->next = p3;
	p3->next = nullptr;


	// 初始化链表结果
	vector<ListNode*> res(3,nullptr);
	res[0] = h;
	res[1] = m;
	res[2] = p;

    ListNode* finres;
    Solution s;
    finres = s.mergeKLists(res);
    while(finres!=nullptr) {
        cout<<finres->val<<" ";
        finres = finres->next;
    }


	return 0;
}
