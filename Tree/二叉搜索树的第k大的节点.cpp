
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
    int kthLargest(TreeNode* root, int k) {
        vector<int> result;
        dfs(result, root);
        return result[k-1];
    }
    
private:
    void dfs(vector<int> &result, TreeNode *node) {

    	// 节点为空的条件下，返回结果值。
        if (node == nullptr) return;
        dfs(result, node->right);
        result.push_back(node->val);
        dfs(result, node->left);
    }
};


int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(2);
    TreeNode* l2 = new TreeNode(1);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;

    cout<<s.kthLargest(root, 2);
	return 0; 

}