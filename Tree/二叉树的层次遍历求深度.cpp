

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
	TreeNode(int v, TreeNode* left, TreeNode* right):val(v),left(nullptr),right(nullptr){}
};

class Solution {
public:
	int getDepth(TreeNode * root) {

		if(root == nullptr) {
			return 0;
		}
		queue<TreeNode*> queue;
		queue.push(root);

		// 只要队列不为空
		int depth = 0;
		while(!queue.empty()) {

			// 层数加一
			depth++;
			int size = queue.size();

			for(int i = 0; i < size; i++) {
				TreeNode* node = queue.front();
				queue.pop();
				if(node->left!=nullptr) {
					queue.push(node->left);

				}
				if(node->right!=nullptr) {
					queue.push(node->right);
				}
			}
		}
		return depth;
	}
};



int main(int argc,char** argv) {

	TreeNode* root = new TreeNode(1);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);

	root->left = l2; 
	root->right = r2;

	Solution s;	
	cout<<s.getDepth(root)<<endl;

	return 0;
}