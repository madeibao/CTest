

// 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

// 树的 最大宽度 是所有层中最大的 宽度 。
// 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，
// 两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。
// 题目数据保证答案将会在  32 位 带符号整数范围内。
// 662. 二叉树最大宽度



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
    int widthOfBinaryTree(TreeNode* root) {
        int Max = 0;

        queue<pair<TreeNode*,long>> queue;
        queue.emplace(root,1);

        
        while(!queue.empty()) {
            int m = queue.size();
            int k = queue.front().second;
            while(m--) {

                auto [p,q] = queue.front();
                queue.pop();
                Max = max(Max,(int)(q-k+1));

                if(p->left != nullptr) {
                    queue.emplace(p->left,2*(q-k));
                }

                if(p->right != nullptr) {
                    queue.emplace(p->right,2*(q-k)+1);
                }
            }
        }
        return Max;
    }
};


int main() {



    return 0;
}