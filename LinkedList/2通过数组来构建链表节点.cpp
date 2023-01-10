
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

// 构建链表

ListNode* createList_array(int *a, int n){
	ListNode *root = new ListNode(-1);
	ListNode *pnode = root;

	for (int i = 0; i < n; ++i) {
		root->val= a[i];//当前节点
		root->next = NULL;

		ListNode *p = new ListNode(-1);//下一个结点
		p->val= a[i + 1];
		p->next = NULL;

		root->next = p;// 连接 当前节点 与 下一个结点
		root = root->next;
	}
	root->next = NULL;//这一句 最重要！！
	return pnode;
}

// 打印链表

void printNode(ListNode *head) {
	while(head->next != nullptr) {
		cout<<head->val<<"->";
		head= head->next;
	}
}

int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,};

	ListNode *head = createList_array(arr, 12);
	printNode(head);

}
