
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
	public:
		bool isValid2(TreeNode* root) {
			return isValid(root, root);
		}

		bool isValid(TreeNode* left, TreeNode* right) {
			if(left==nullptr&&right==nullptr) {return true;}
			if(left==nullptr||right==nullptr) {return false;}

			return left->val==right->val&&isValid(left->left, right->right)&&isValid(left->right, right->left);

		}
};



int main(int argc, char** argv) {
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(2);

	root->left = left;
	root->right = right;

	Solution s;
	cout<<s.isValid2(root)<<endl;

	return 0;
}
