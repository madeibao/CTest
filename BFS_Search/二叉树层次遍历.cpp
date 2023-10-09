
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	if(root == nullptr) {
    		return res;
    	}
    	queue<TreeNode*> queue2;

    	queue2.push(root);

    	while(!queue2.empty()) {

    		vector<int> temp;
    		int size = queue2.size();
    		for(int i = 0; i < size;i++) {
    			TreeNode* node = queue2.front();
    			queue2.pop();
    			temp.push_back(node->val);
    			if(node->left!=nullptr)queue2.push(node->left);
    			if(node->right!=nullptr)queue2.push(node->right);

    		}
    		res.push_back(temp);
    	}
    	return res;
    }
};


int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;
    vector<vector<int>> res;
    res = s.levelOrder(root);
    for(auto i:res) {
    	for(auto j:i) {
    		cout<<j<<" ";
    	}
    	cout<<endl;
    }

    return 0;
}
