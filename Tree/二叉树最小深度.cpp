



class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root==nullptr) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(!root->left||!root->right) {
            return left==0?right+1:left+1;
        }
        else {
            return min(left,right)+1;
        }
    }
};