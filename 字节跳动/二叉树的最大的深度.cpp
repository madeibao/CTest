
 #include<iostream>
 #include<bits/stdc++.h>

 using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
 };

class Solution {
public:
    /**
     * @param root TreeNode类
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sub_left = maxDepth(root->left);
        int sub_right = maxDepth(root->right);
        return (sub_left > sub_right ? sub_left : sub_right) + 1;
    }
};

int main(int argc, char** argv) {

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	n1->left = n2;
	n1->right = n3;

	Solution s;
	cout<<s.maxDepth(n1)<<endl;

	return 0;
}
