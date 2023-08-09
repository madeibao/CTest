

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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root==nullptr) {
            return res;
        }
        helper(root);
        return res;
    }

    void helper(TreeNode* root) {

    	if(root==nullptr) {
    		return;
    	}

    	queue<TreeNode*> queue2;
    	queue2.push(root);

    	int flag = 0;
    	while(!queue2.empty()) {

    		vector<int> temp;
    		int n = queue2.size();

    		for(int i=0;i<n;i++) {
    			TreeNode* node = queue2.front();
    			int val = node->val;
    			temp.push_back(val);
    			queue2.pop();
    			if(node->left!=nullptr) {
    				queue2.push(node->left);
    			}
    			if(node->right!=nullptr) {
    				queue2.push(node->right);
    			}
    		}

    		if(flag%2==1) {
    			reverse(temp.begin(),temp.end());
    		}
    		res.push_back(temp);
    		flag++;
    	}
    }
};

int main() {
	TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;

    vector<vector<int>> res;

    Solution s;

    res = s.zigzagLevelOrder(root);
    for(auto i:res) {
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}


