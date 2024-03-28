
 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {

       if(root==NULL){
           return false;
       }

       if(root->val==targetSum && root->right==NULL && root->left==NULL)
       return true;

       if(root->right!=NULL)
    root->right->val+=root->val;
       if(root->left!=NULL)
       root->left->val+=root->val;


    return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);
    }
};