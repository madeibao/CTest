

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):left(nullptr),right(nullptr),val(x) {}
}TreeNode;


// 堆成的二叉树

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) {
            return true;
        }
        return helper(root, root);
    }

private:
    bool helper(TreeNode* left,TreeNode* right) {
        if(left==nullptr&&right==nullptr) {
            return true;
        }
        if(left==nullptr||right==nullptr) {
            return false;
        }

        return (left->val==right->val)&&helper(left->left, right->right)&&helper(left->right, right->left);
    }
};


int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(2);

    root->left = l2;
    root->right = r2;

    Solution s;
    cout<<s.isSymmetric(root)<<endl;
    return 0;
}


