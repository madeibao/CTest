


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):left(nullptr),right(nullptr),val(x) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* root, int i){
        if (root == nullptr) return 0;
        int temp = i * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return temp;
        return helper(root->left, temp) + helper(root->right, temp);
    }
};

int main(int argc, char** arg) {


    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);

    root->left = l2;
    root->right = l3;


    Solution s2;

    cout<<s2.sumNumbers(root)<<endl;

}


// 12 + 13 = 25

