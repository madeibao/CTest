

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(nullptr) {}
};


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here

        ListNode* res;
        if(l1==nullptr) {
        	return l2;
        }

        if(l2==nullptr) {
        	return l1;
        }


        if(l1->val<l2->val) {
        	res =l1;
        	res->next = mergeTwoLists(l1->next, l2);
        }
        else {
        	res=  l2;
        	res->next = mergeTwoLists(l1,l2->next);
        }

        return res;
    }
};


int main(){

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    n1->next  = n2;
    n2->next  = n3;
    n3->next  = nullptr ;

    ListNode* h1 = new ListNode(2);
    ListNode* h2 = new ListNode(3);
    h1->next = h2;
    h2->next = nullptr;

    Solution s;
    ListNode* res;
    res  = s.mergeTwoLists(n1, h1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }
    return 0;

}
