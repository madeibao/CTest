
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    /**
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here

        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> queue;

        queue.push(root);
        while(!queue.empty()) {
            int n = queue.size();
            vector<int> temp;
            for(int i=0;i<n;i++) {
                TreeNode* node = queue.front();
                temp.push_back(node->val);
                queue.pop();
                if(node->left!=nullptr) {
                    queue.push(node->left);
                }
                if(node->right!=nullptr) {
                    queue.push(node->right);
                }
            }
            res.push_back(temp);
        }

        for(int i=0;i<res.size();i++) {
            if(i%2==1) {
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])  {

    TreeNode* root =new TreeNode(1);
    TreeNode* h2 = new TreeNode(2);
    TreeNode* h3 = new TreeNode(3);

    root->left = h2;
    root->right = h3;

    Solution s;
    vector<vector<int>> res;

    res=  s.zigzagLevelOrder(root);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}



