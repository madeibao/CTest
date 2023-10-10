

#include<iostream>

using namespace std;

struct TreeNode {
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int x) : left(nullptr), right(nullptr), val(x) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> queue;

        if(root==nullptr) {
            return 0;
        }

        queue.push(root);
        int res = 0;
        while(!queue.empty()) {
            int len = queue.size();
            for(int i=0;i<len;i++) {
                TreeNode* node = queue.front();
                queue.pop();

                res++;
                if(node->left!=nullptr) {
                    queue.push(node->left);
                }
                if(node->right!=nullptr) {
                    queue.push(node->right);
                }
            }
        }

        return res;
    }
};


int main(int argc, char *argv[]) {
	TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;

    Solution s;
    cout<<s.countNodes(root)<<endl;
}
