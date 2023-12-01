
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        if(root == nullptr) {
            return res;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        // 判断队列是否为空
        while(!queue.empty()) {
            
            int n = queue.size();
            double sum = 0;

            for(int i=0;i<n;i++) {
                TreeNode* node = queue.front();
                queue.pop();
                sum += node->val;

                if(node->left != nullptr) {
                    queue.push(node->left);
                }

                if(node->right!=nullptr) {
                    queue.push(node->right);
                }
            }
            res.emplace_back(sum/n);
        }
        return res;
    }
};


int main() {



    return 0;
}