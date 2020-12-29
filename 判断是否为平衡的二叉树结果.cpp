


#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

struct TreeNode {

	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};



class Solution {
	public:
		int f=1;
		int getHeight(TreeNode *head) {
			if(head == NULL) {
				return 0;
			}

			int l = getHeight(head->left);
			int r = getHeight(head->right);

			if(abs(l - r)>1) {
				f = 1;
			}
			return max(l,r)+1;
		}

		
	private:
		bool isBalanced(TreeNode *head) {

			getHeight(head);
			if(f) {
				return true;
			}
			else {
				return false; 
			}
		}
};

int main(int argc, char *argv[]) {

    TreeNode *head= new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(2);

    head->left= n2;
    head->right=n3;

    Solution s;

    cout<<s.isBalanced(head)<<endl;

    return 0;
}