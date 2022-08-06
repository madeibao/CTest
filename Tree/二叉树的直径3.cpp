
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
    int deep(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = deep(root->left);
        int right = deep(root->right);
        ans = max(ans, left + right + 1);  //更新遍历到的节点的最大深度
        return max(left, right) + 1;       //返回当前节点的深度
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        deep(root);
        return ans - 1;
    }
private:
    int ans = 0;
};


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

