
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* left, TreeNode* right):val(v), left(left), right(right) {}
};

class Solution {
	public:
		int diameterOfBinaryTree(TreeNode* root) {
			if(root == nullptr) {
				return 0;
			}
			int res = 0;
			helper(root, res);
			return res;
		}

		int helper(TreeNode* root,int& res) {
			if(root == nullptr) {
				return 0;
			}

			int left = helper(root->left, res);
			int right = helper(root->right, res);

			left = (root->left)?left+1:left;
			right = (root->right)?right+1:right;

			res = max(res,left+right);
			return max(left, right);
		}
};


/**
class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root ->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = maxDepth(root -> left) + maxDepth(root->right);
        return max(res, max(diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right)));
    }
};

*/

int main(int argc, char* argv[]) {

	TreeNode* root = new TreeNode(1);
	TreeNode* l2  = new TreeNode(2);
	TreeNode* r2  = new TreeNode(3);

	root->left = l2;
	root->right = r2;

	Solution s;
	cout<<s.diameterOfBinaryTree(root);
	return 0;
}

