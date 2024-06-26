
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
    private:
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL)
        return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    int helper(TreeNode* root, int low, int high){
         if (!root) return 0;

       if (root->val < low)
           return helper(root->right, low, high);

       if (root->val > high)
           return helper(root->left, low, high);

       return root->val + helper(root->left, low, high) + helper(root->right, low, high);

        
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        /*vector<int> ans;
        inorder(root,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                sum+=ans[i];
            }
        }*/
return helper(root,low,high);

    }
};