

// k 个一组来进行链表的翻转。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};


// 链表遍历
while(res!=nullptr) {
	cout<<res->val<<" ";
	res = res->next;
}


int main(int argc, char** argv) {


	//-----------------------------------------------------------------------------------------
	ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;




    //--------------------------------------------------------------------------------

	ListNode* a = new ListNode(9);
	ListNode* b = new ListNode(8);
	ListNode* c = new ListNode(7);
	ListNode* d = new ListNode(6);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(4);
	ListNode* g = new ListNode(3);
	ListNode* h = new ListNode(2);
	ListNode* j = new ListNode(1);


	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = j;
	j->next = nullptr;



    Solution s;
    ListNode * res = s.exchange(head);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;

}



int main(int argc, char** argv) {

    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;



    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(2);


    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = nullptr;




    int k(2);

    Solution s;
    ListNode * res = s.reverseKGroup(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;

}

