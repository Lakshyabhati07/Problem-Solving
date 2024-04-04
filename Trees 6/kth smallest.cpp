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
 

class Solution {
//APPROACH 1
public:
    TreeNode* node;
    void inorder(TreeNode* root,int &k){
        
        if(root==NULL || k<0 )
        return;

        inorder(root->left,k);
        k--;
        if(k==0)  
            node=root;
        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
     
        inorder(root,k);
        return node->val;
    }
};