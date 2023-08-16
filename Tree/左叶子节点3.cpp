
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){};
};

class Solution {
public:
	int getLeastNumbers(TreeNode* root){

		if(root==nullptr){
			return 0;
		}

		int res = 0;
		TreeNode* lefta = root->left;
		if(lefta&&!lefta->left&&!lefta->right){
			res+=lefta->val;
			getLeastNumbers(root->right);
		}
		else {
			getLeastNumbers(root->left);
			getLeastNumbers(root->right);
		}
		return res;
	}
};


int main(int argc, char** argv) {

	TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;
    Solution s;
    cout<<s.getLeastNumbers(root)<<endl;

	return 0;
}


