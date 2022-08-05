
#include "iostream"
#include "bits/stdc++.h"

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B)
        {
            A = A ? A->next : headB;
            B = B ? B->next : headA;
        }
        return A;
    }
};

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



    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(9);
    ListNode* c = new ListNode(8);

    a->next = b;
    b->next = c;
    c->next = n3;

    ListNode* res;
    Solution s;
    res = s.getIntersectionNode(head,a);
    while ( res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;
}
