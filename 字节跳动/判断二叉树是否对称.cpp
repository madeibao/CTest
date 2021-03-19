
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isSymmetric(TreeNode* root) {
        // write code here

      	if(root==nullptr) {
      		return true;
      	}
      	return helper(root, root);

    }


    bool helper(TreeNode* left, TreeNode* right) {
    	if(left==nullptr&&right==nullptr) {
    		return true;
    	}

    	if(left==nullptr||right==nullptr) {
    		return false;
    	}

    	return (left->val==right->val)&&(helper(left->left,right->right))&&(helper(left->right, right->left));
    }
};


int main(int argc, char* argv[]) {

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(2);

	n1->left = n2;
	n1->right = n3;

	Solution s;
	cout<<s.isSymmetric(n1)<<endl;
	return 0;
}
