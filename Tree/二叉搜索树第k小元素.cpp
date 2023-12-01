



class Solution {
public:
    vector<int> res;
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return res[k-1];
    }

    void helper(TreeNode* root  ) {
        if(root==nullptr) {
            return;
        }

        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
};