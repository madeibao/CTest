
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	return help(root, root);
    }

    bool help(TreeNode* ta, TreeNode* tb) {
        if(ta==nullptr&&tb==nullptr) {
    		return true;
    	}

    	if(ta==nullptr||tb==nullptr) {
    		return false;
    	}

    	return (ta->val==tb->val)&&help(ta->left,tb->right)&&help(ta->right,tb->left);
    }
};


int main(int argc, char** argv) {

	Solution s;
	
	TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    root->left = left;
    root->right = right;

    cout<<s.isSymmetric(root)<<endl;
	return 0;
}
