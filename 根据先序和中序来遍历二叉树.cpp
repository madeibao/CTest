// 矩阵的查找算法。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v), left(nullptr),right(nullptr){}

};


class Solution {
public:
    TreeNode* reBuild(vector<int>& pre,vector<int>& vin,int pre_left,int pre_right,int vin_left,int vin_right){


        // 先序遍历序列的指针位置不符合。
        if(pre_left>pre_right)return nullptr;
        int index = 0;
        for(int i = vin_left; i<=vin_right;i++) {

            // 获得的是根节点的值。
            if(vin[i]==pre[pre_left]) {
                index = i;
                break;
            }
        }

        TreeNode* node =new TreeNode(vin[index]);


        // 参数的设置情况， 开始参数，结束参数。
        node->left = reBuild(pre, vin, pre_left+1,pre_left+index-vin_left,vin_left,index-1);
        node->right = reBuild(pre, vin, pre_left+index+1-vin_left, pre_right, index+1, vin_right);


        // 注意参数变化： pre_left+index-vin_left   pre_left+index-vin_left+1 
        return node;
    }


    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reBuild(pre,vin,0,pre.size()-1,0,vin.size()-1);
    }
};


void preOrder(TreeNode* root) {
    if(root==nullptr) {return;}
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main() {

    // 给定的是前序和中序的遍历结果。

    vector<int> pre = {1,2,3,4,5,6,7};
    vector<int> mid = {3,2,4,1,6,5,7};

    Solution s;
    TreeNode* root = s.reConstructBinaryTree(pre, mid);
    preOrder(root);
    return 0;
}



