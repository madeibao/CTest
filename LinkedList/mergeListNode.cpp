

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);

        ListNode* temp = dummy;

        while(l1&&l2) {
            if(l1->val<l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1==nullptr?l2:l1;

        return dummy->next;

    }
};


int main(int argc, char* argv[]) {
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
    ListNode* c = new ListNode(8);
    ListNode* d = new ListNode(10);
    ListNode* e = new ListNode(12);
    ListNode* f = new ListNode(13);


    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = nullptr;


    Solution s;
    ListNode* res;
    res = s.mergeTwoLists(head,a);
    while (res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;
}

