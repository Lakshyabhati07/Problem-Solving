
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
public:
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* ele1=NULL,*ele2=NULL;
    TreeNode* middle=NULL;
    void inorder(TreeNode* root){
           if(root==NULL)  return;

        inorder(root->left);

        if(root->val < prev ->val && prev!=NULL){
            if(ele1==NULL)
           { ele1=prev;
            middle=root;
            }

            else ele2=root;
        }

      
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(ele1&&ele2) swap(ele1->val,ele2->val);
        else if(ele1 && middle) swap(ele1->val , middle->val);
    }
};