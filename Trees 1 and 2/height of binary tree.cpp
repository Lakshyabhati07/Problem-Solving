#include<bits/stdc++.h>
using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
int heightOfBinaryTree(TreeNode *root)
{
	// Write your code here.
        if(root==NULL)
        return 0;


    int left=heightOfBinaryTree(root->left);
    int right =heightOfBinaryTree(root->right);

    int ans= max(left,right)+1;
    return ans;

}
