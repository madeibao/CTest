
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): val(val),left(nullptr),right(nullptr) {}
	TreeNode(int v, TreeNode *left, TreeNode *right):val(v),left(left),right(right) {}
};

class Solution {
public:
	int findKthLargest(TreeNode* root,int k) {
		if(root == nullptr) {
			return -1;
		}
        vector<int> result;
		mid(result, root);
		return result[k-1];
	}

	// 中序遍历保存结果值。
	void mid(vector<int> & nums, TreeNode * root) {
		if(root == nullptr) return;
		mid(nums, root->left);
		nums.push_back(root->val);
		mid(nums, root->right);
	}
};



int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(2);
    TreeNode* l2 = new TreeNode(1);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;

    cout<<s.findKthLargest(root, 2);
	return 0;

}
