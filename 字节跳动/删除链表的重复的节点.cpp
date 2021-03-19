
#include<iostream>
#include<bits/stdc++.h>


using namespace std; 

struct ListNode {	
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr){}
};


class Solution {
public:
    /**
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here

    	if(head==nullptr||head->next==nullptr) {
    		return head;
    	}

    	ListNode* p = head;
		
    	while(p!=nullptr&&p->next!=nullptr) {
    		if(p->val==p->next->val) {
    			p->next = p->next->next;
    		}
    		else {
    			p = p->next;
    		}
    	}

    	return p;
    }
};

int main(int argc, char** argv) {

	ListNode* head= new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(2);

	head->next = n2;
	n2->next  = n3;
	n3->next  = nullptr;

	ListNode* res;
	Solution s; 

	res = s.deleteDuplicates(head);	


	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}