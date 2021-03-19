
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){}
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
       if(root == NULL)
           return false;
        if(root->left == NULL && root->right == NULL && sum - root->val == 0)
           return true;
           
       	return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};



int main(int argc, char **argv) {

    TreeNode root =new TreeNode(1);
    TreeNode left =new TreeNode(2);
    root->left = left;
    Solution s;

    cout<<s.hasPathSum(root, 3);

    return 0;
}