
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     *
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if (!t1 && !t2) {
            return NULL;
        }
        if (!t1) {
            return t2;
        }
        if (!t2){
            return t1;
        }
        t1->val+=t2->val;
        t1->left=mergeTrees(t1->left, t2->left);
        t1->right=mergeTrees(t1->right, t2->right);
        return t1;
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

	TreeNode* n1= new TreeNode(1);
	TreeNode* n2= new TreeNode(2);
	TreeNode* n3= new TreeNode(3);

	n1->left=n2;
	n1->right=n3;

	TreeNode* h1 = new TreeNode(1);
	TreeNode* h2 = new TreeNode(2);
	TreeNode* h3 = new TreeNode(2);

	h1->left = h2;
	h1->right = h3;

	Solution s;
	TreeNode* root = s.mergeTrees(n1, h1);
	preOrder(root);

	return 0;
}
