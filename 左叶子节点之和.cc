

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {

	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x) ,left(NULL),right(NULL){}
};

class Solution {
public:
	int sumLeft(TreeNode *root) {
		int sum = 0, left =0, right =0;
		if(root==nullptr) {
			return 0;
		}
		if(root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr ){
			sum += root->left->val;
		}
		else {
			left = sumLeft(root->left);
		}
		right = sumLeft(root->right);
		return sum + left + right;
	}
};

int main(int argc, char *argv[]) {
	TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;

    Solution s;
    cout<<s.sumLeft(root)<<endl;
}
