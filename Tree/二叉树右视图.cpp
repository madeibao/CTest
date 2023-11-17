
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;

        if(root==nullptr) {
            return res;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        // 队列不为空的条件下
        while(!queue.empty()) {
            int n = queue.size();
            
            for(int i=0;i<n;i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if(node->left!=nullptr) {
                    queue.push(node->left);
                }
                if(node->right!=nullptr) {
                    queue.push(node->right);
                }
                if(i==n-1) {
                    res.push_back(node->val);
                }
            }
        }

        return res;
    }

};
