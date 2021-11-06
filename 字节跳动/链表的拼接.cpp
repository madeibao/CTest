
#include "iostream"
#include "bits/stdc++.h"

using namespace std; //

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v) {}
	ListNode(int v, ListNode* next):val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* listhead = list1;
        for (int i = 0; i < a - 1; i++) {
            list1 = list1->next;
        }

        // 指向了删除的节点前面的一个位置上。
        ListNode* frontend = list1;

        cout<<frontend->val<<" ";
        for (int i = 0; i < b - a + 2; i++) {
            list1 = list1->next;
        }
        // 指向了删除节点的后一个位置上
        ListNode* backfront = list1;

        frontend->next = list2;
        while (list2->next)
        {
            list2 = list2->next;
        }
        list2->next = backfront;
        return listhead;
    }
};

int main(int argc, char** argv ) {

	ListNode* head= new ListNode(0);
	ListNode* ha= new ListNode(1);
	ListNode* hb= new ListNode(2);
	ListNode* hc= new ListNode(3);
	ListNode* hd= new ListNode(4);
	ListNode* he= new ListNode(5);

	head->next = ha;
	ha->next = hb;
	hb->next = hc;
	hc->next = hd;
	hd->next = he;
	he->next = nullptr;


	ListNode* ma = new ListNode(8);
	ListNode *mb = new ListNode(9);
	ListNode *mc = new ListNode(10);

	ma->next = mb;
	mb->next = mc;
	mc->next = nullptr;

	Solution s;
	ListNode * res;

	int m(3),n(4);

	res = s.mergeInBetween(head,m, n,ma);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}
