
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int x) : left(nullptr), right(nullptr), val(x) {}
};


TreeNode*mergeTrees(TreeNode*root1, TreeNode*root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    if (root1 && root2)
        root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);    //递归合并左子树
    root1->right = mergeTrees(root1->right, root2->right); //递归合并右子树
    return root1;
}


void preTravel(TreeNode* root) {
	if(root== nullptr) {
		return;
	}
	cout<<root->val<<" ";
	preTravel(root->left);
	preTravel(root->right);
}
int main(int argc, char* argv[]) { //
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;


    TreeNode* root2 = new TreeNode(1);
    TreeNode* l22 = new TreeNode(2);
    TreeNode* r22 = new TreeNode(3);

    root2->left = l22;
    root2->right = r22;


    TreeNode* res;
    res = mergeTrees(root,root2);
    preTravel(res);

    return 0;
}

