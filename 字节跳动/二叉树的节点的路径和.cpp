

#include<iostream>
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
    bool hasPathSum(TreeNode *root, int sum) {
           if (nullptr == root) return false;
            else if (root->val == sum &&root->left == nullptr &&root->right == nullptr) {
                return true;
            }
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


int main(int argc, char **argv) {


	TreeNode* root = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);

	root->left  = n2;
	root->right = n3;

	Solution s;

	int k(3);

	cout<<s.hasPathSum(root, k)<<endl;

	return 0;
}
