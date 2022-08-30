

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
	TreeNode(int x,TreeNode *left, TreeNode *right):val(x),left(nullptr),right(nullptr){}
};


class Solution {
public:

    // 求出树的高度值。
    int TreeDepth(TreeNode *root) {
        if(root==NULL) {
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return 1+max(TreeDepth(root->left),TreeDepth(root->right));
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        if(abs(TreeDepth(pRoot->left)-TreeDepth(pRoot->right))>1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};


int main(int argc, char* argv[]) {

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	n1->left = n2;
	n1->right = n3;

	Solution s;
	cout<<s.IsBalanced_Solution(n1);
	return 0;
}
