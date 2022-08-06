

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
	TreeNode(int v, TreeNode* left, TreeNode* right):val(v),left(nullptr),right(nullptr){}
};


class Solution {
public:
	vector<vector<int> > levelTravel(TreeNode* root) {
		vector<vector<int> > result;

		if(root==nullptr) {
			return result;
		}
		queue<TreeNode*> queue;

		// 二叉树不为空
		queue.push(root);
		// 队列不为空的条件下。
		while(!queue.empty()) {
			int size = queue.size();
			vector<int> temp;
			for(int i=0;i<size;i++) {
				TreeNode* node = queue.front();
				queue.pop();
				temp.push_back(node->val);
				if(node->left!=nullptr) {
					queue.push(node->left);
				}

				if(node->right!=nullptr) {
					queue.push(node->right);
				}
			}
			result.push_back(temp);
		}

		// 从前到后面的来翻转。
		reverse(result.begin(),result.end());
		return result;
	}

};


int main() {

	TreeNode* root = new TreeNode(1);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);

	root->left = l2;
	root->right = r2;

	Solution s;
	vector<vector<int> > res;
	res = s.levelTravel(root);
	for(auto i :res) {
		for(auto j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
