


//通过层次遍历方法来确定二叉树的深度

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        int minLevel = 0;

        queue<TreeNode*> layers;

        if (root) {
            layers.push(root);
        }
        while(!layers.empty()) {
            minLevel++;
            int size = layers.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = layers.front();
                layers.pop();
                if (!node->left && !node->right) {
                    return minLevel;
                }
                if (node->left) {
                    layers.push(node->left);
                }
                if (node->right) {
                    layers.push(node->right);
                }
            }
        }

        return minLevel;
    }
};

int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;
    cout<<s.minDepth(root)<<endl;

    return 0;
}

