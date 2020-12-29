
#include <stdio.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList_array(int *a, int n) {
	ListNode *root = new ListNode();
	ListNode *pnode = root;

	for (int i = 0; i < n - 1; ++i) {
		root->val = a[i];//当前节点
		root->next = NULL;

		ListNode *p = new ListNode();//下一个结点
		p->val= a[i + 1];
		p->next = NULL;

		root->next = p;// 连接 当前节点 与 下一个结点
		root = root->next;
	}
	root->next = NULL;//这一句 最重要！！
	return pnode;
}

void display(ListNode* head) {
    if(head==nullptr) {
        return;
    }

    while(head!=nullptr) {
        cout<<head->val<<"->";
        head= head->next;
    }
}

int main() {
	int a[] = { 1, 3, 5, 7, 9 };
	int n = sizeof(a) / sizeof(a[0]);
	ListNode *pnode = createList_array(a, n);

    display(pnode);
    return 0;
}

