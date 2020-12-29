
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void firstOrder(TreeNode *head) {
	if(head == nullptr) {
        return;
	}
    cout<<head->val<<" ";
    firstOrder(head->left);
    firstOrder(head->right);

}

// 非递归的方式来遍历二叉树。
void preOrder2(TreeNode *head) {

	if(head == nullptr) {
		return;
	}

	stack<TreeNode*> stack2;
	stack2.push(head);

    while(!stack2.empty()) {
		TreeNode *node = stack2.top();
		cout <<node->val<<" ";
		stack2.pop();

		// 先序遍历的特点。
        if(node->right != nullptr) {
			stack2.push(node->right);
		}

		if(node->left != nullptr) {
			stack2.push(node->left);
		}
	}
}


// 中序遍历二叉树的节点值。
void inOrder(TreeNode *head) {

	if(head == nullptr) {
        return;
	}
    inOrder(head->left);
    cout<<head->val<<" ";
    inOrder(head->right);

}

void postOrder(TreeNode *head) {

	if(head == nullptr) {
		return;
	}

	postOrder(head->left);
	postOrder(head->right);
	cout<<head->val<<" ";

}


int main() {

	TreeNode *head = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(3);
    head->left = l2;
    head->right = r2;
	inOrder(head);

	cout<<"\n------------------------------"<<endl;
	preOrder2(head);
	return 0;
}
