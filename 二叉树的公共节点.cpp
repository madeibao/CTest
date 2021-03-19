
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {

public:
	TreeNode* ancestor(TreeNode*root, TreeNode* p, TreeNode* q) {

		if(root == nullptr|| root==p|| root==q) {
			return root;
		}

		TreeNode* left = ancestor(root->left, p,q);
		TreeNode* right = ancestor(root->right,p,q);

		if(left&&right) {
			return root;
		}

		return left?left:right;
	}
};







