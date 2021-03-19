
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
	ListNode* reverse(ListNode* head ) {

		ListNode* pre = nullptr;
		while( head!=nullptr ) {
			ListNode* temp = head->next;
			head->next =  pre;
			pre = head;
			head = temp;
		}

		return pre;
	}
};


// 递归算法来实现链表的逆置。

class Solution{ 
public:
	ListNode* reverse(ListNode* head) {

		// 递归一定有结束的条件。
		if(head==nullptr||head->next==nullptr) {return head;}

		ListNode* temp = head->next;
		ListNode* res = reverse(temp);
		head->next->next = head;
		head->next = nullptr;
		return res;
	}
};


int main(int argc, char* argv[]) {

	ListNode* head= new ListNode(1);
	ListNode* n2= new ListNode(2);
	ListNode* n3= new ListNode(3);
	ListNode* n4= new ListNode(4);
	ListNode* n5= new ListNode(5);


	head->next= n2;
	n2->next= n3;
	n3->next= n4;
	n4->next= n5;
	n5->next= nullptr;


	ListNode* res;
	Solution s;
	res = s.reverse(head);
	while( res!=nullptr) {
		cout<<res->val<<endl;
		res =res->next;
	}
	return 0;
}
