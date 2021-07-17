
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot == nullptr) {
			return true;
		}
        if(pRoot->left==nullptr&&pRoot->right==nullptr) {
            return true;
        }
        return abs(getHeight(pRoot->left)-getHeight(pRoot->right))<=1&&IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);

	}
	int getHeight(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr) {
            return 1;
        }
        return 1+max(getHeight(root->left),getHeight(root->right));
	}
};

int main(int argc, char*argv[]) {
	TreeNode* root = new TreeNode(1);
	TreeNode* r2 = new TreeNode(2);
	TreeNode* r3 = new TreeNode(3);

	root->left = r2;
	root->right = r3;

	Solution s;
	cout<<s.IsBalanced_Solution(root);

	return 0;
}
