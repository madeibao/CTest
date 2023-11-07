

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
    vector<int> rightSideView(TreeNode* root) {

        if(root==nullptr) {
            return {};
        }

        vector<int> res;
    	queue<TreeNode*> queue2;
    	queue2.push(root);

    	while (!queue2.empty()) {
    		int n = queue2.size();

    		for (int i=0;i<n;i++) {
    			TreeNode* node = queue2.front();
                queue2.pop();
    			if(node->left!=nullptr) {
    				queue2.push(node->left);
    			}
    			if(node->right!=nullptr) {
    				queue2.push(node->right);
    			}
    			if(i==n-1) {
    				res.push_back(node->val);
    			}
    		}
    	}

    	return res;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);

    root->left = l2;
    root->right = l3;

    Solution s2;
    vector<int> res;
    res =s2.rightSideView(root);
    for(auto i:res) {
    	cout<<i<<" "<<endl;
    }

    return 0;
}