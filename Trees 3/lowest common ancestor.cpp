
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q){
            return root;
        }

        TreeNode* lefti= lowestCommonAncestor(root->left,p,q);
        TreeNode* righty= lowestCommonAncestor(root->right,p,q);

        if(lefti==NULL)
        return righty;

        else if(righty==NULL)
        return lefti;

        else
        return root;
    }
};