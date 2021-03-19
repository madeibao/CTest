

#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    void dfs(TreeNode *root, int path, int &sum) {
        if (!root) return;
        path = 10 * path + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += path;
        } 
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
        
//         path = path / 10;
    }
   
    int sumNumbers(TreeNode* root) {
        // write code here
        int sum = 0;
        int path = 0;
        dfs(root, path, sum);
        return sum;
    }
};


int main(int argc, char* argv[] ) {


	TreeNode* root = new TreeNode(1);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* l3 = new TreeNode(3);

	root->left = l2;
	root->right = l3;

	Solution s; 
	cout<<s.sumNumbers(root)<<endl;
	return 0;
}