


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
    	if(pRoot==nullptr) {
    		return;
    	}

    	TreeNode* temp = pRoot->left;
    	pRoot->left = pRoot->right;
    	pRoot->right = temp;
    	Mirror(pRoot->left);
    	Mirror(pRoot->right);
    }
};



void preOrder(TreeNode* root) {

	if(root==nullptr) {
		return;
	}

	cout<<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}


int main(int argc, char **argv) {

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);

	n1->left = n2;
	n1->right = n3;

	Solution s;

	preOrder(n1);
	s.Mirror(n1);
	cout<<endl;
	preOrder(n1);

	return 0;
}
